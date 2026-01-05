#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    for(string s : participant){
        if(m.find(s) == m.end()){
            m[s] = 1;
        }
        else{m[s]++;}
    }
    for(string s : completion){
        m[s]--;
    }
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        for(int i=0;i<iter->second;i++){
            answer = answer + iter->first + " ";
        }
    }
    answer = answer.substr(0, answer.length()-1);
    return answer;
}
