#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, int> m;
string solution(vector<string> survey, vector<int> choices) {
    for(char i = 'A';i<='Z';i++){m[i] = 0;}
    string answer = "";
    for(int i=0;i<survey.size();i++){
        switch(choices[i]){
            case 1:
                m[survey[i][0]]+=3;
                break;
            case 2:
                m[survey[i][0]]+=2;
                break;
            case 3:
                m[survey[i][0]]+=1;
                break;
            case 5:
                m[survey[i][1]]+=1;
                break;
            case 6:
                m[survey[i][1]]+=2;
                break;
            case 7:
                m[survey[i][1]]+=3;
                break;
        }
    }
    
    if(m['R'] >= m['T']){answer = answer + "R";}
    else{answer = answer + "T";}
    
    if(m['C'] >= m['F']){answer = answer + "C";}
    else{answer = answer + "F";}
    
    if(m['J'] >= m['M']){answer = answer + "J";}
    else{answer = answer + "M";}
    
    if(m['A'] >= m['N']){answer = answer + "A";}
    else{answer = answer + "N";}
    
    return answer;
}
