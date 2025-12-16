#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> name_conv; map<int, string> num_conv;
    for(int i=0;i<friends.size();i++){
        name_conv[friends[i]] = i;
        num_conv[i] = friends[i];
    }
    
    int present_count[50][50] = {0};
    
    map<string, int> present_jisu;
    for(int i=0;i<friends.size();i++){
        present_jisu[friends[i]]= 0;
    }
    
    for(string str : gifts){
        stringstream ss(str);
        string part1, part2;
    
        ss >> part1 >> part2; 
        
        present_count[name_conv[part1]][name_conv[part2]]++;
        
        present_jisu[part1]++;
        present_jisu[part2]--;
    }
    
    for(int i=0;i<friends.size();i++){
        int count = 0;
        for(int j=0;j<friends.size();j++){
            if(i==j){continue;}
            if(present_count[i][j] > present_count[j][i]){
                count++;
            }
            else if(present_count[i][j] < present_count[j][i]){
                
            }
            else{
                if(present_jisu[num_conv[i]] > present_jisu[num_conv[j]]){
                    count++;
                }
            }
        }
        answer = max(answer, count);
    }
    
    return answer;
}
