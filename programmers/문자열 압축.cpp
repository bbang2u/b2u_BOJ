#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length(); 

    for(int i=1; i<=s.length() / 2; i++){
        string tmp = "";
        
        string target = s.substr(0, i); 
        int recur = 1;

        for(int j=i; j<s.length(); j+=i){
            string cur = s.substr(j, i); 
            
            if(target == cur){
                recur++;
            } 
            else {
                if(recur > 1) tmp += to_string(recur);
                tmp += target;

                target = cur;
                recur = 1;
            }
        }
        
        if(recur > 1) tmp += to_string(recur);
        tmp += target;
        
        answer = min(answer, (int)tmp.length());
    }
    return answer;
}
