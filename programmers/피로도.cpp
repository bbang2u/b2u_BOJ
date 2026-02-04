#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> v;
    for(int i=0;i<dungeons.size();i++){
        v.push_back(i);
    }
    
    do{
        int cur = k;
        int count = 0;
        for(int i=0;i<v.size();i++){
            if(cur >= dungeons[v[i]][0]){
                count++;
                cur-=dungeons[v[i]][1];
            }
        }
        answer = max(answer, count);
    
    } while (next_permutation(v.begin(), v.end()));
    
    if(answer == 0){answer = -1;}
    return answer;
}
