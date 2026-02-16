#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<string> s;
    int p_left = 0; int p_up = 0;
    for(int i=0;i<dirs.length();i++){
        int left = p_left; int up = p_up;
        if(dirs[i] == 'L'){
            left++;
            if(left>5){continue;}
        }
        if(dirs[i] == 'R'){
            left--;
            if(left<-5){continue;}
        }
        if(dirs[i] == 'U'){
            up++;
            if(up>5){continue;}
        }
        if(dirs[i] == 'D'){
            up--;
            if(up<-5){continue;}
        }
        string a = to_string(left) +","+to_string(up)+"/"+to_string(p_left) +","+to_string(p_up);
        string b = to_string(p_left) +","+to_string(p_up)+"/"+to_string(left) +","+to_string(up);
        if(s.find(a) == s.end()){
            answer++;
            s.insert(a);
            s.insert(b);
        }
        p_left = left;
        p_up = up;
    }
    return answer;
}
