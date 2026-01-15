#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> s;
    set<int> exclude;
    for(int i=0;i<number.length();i++){
        while(!s.empty()){
            if(number[s.top()] < number[i]){
                exclude.insert(s.top());
                s.pop();
                k--;
                if(k==0){break;}
            }
            else{break;}
        }
        s.push(i);
        if(k==0){break;}
    }
    for(int i=0;i<number.length() - k;i++){
        if(exclude.find(i) != exclude.end()){continue;}
        answer+=number[i];
    }
    return answer;
}
