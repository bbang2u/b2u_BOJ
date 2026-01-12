#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int a[5] = {1,2,3,4,5};
int b[8] = {2,1,2,3,2,4,2,5};
int c[10] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    int ia, ib, ic;
    ia = ib = ic = 0;
    
    int sa, sb, sc;
    sa = sb = sc = 0;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i] == a[ia]){sa++;}
        if(answers[i] == b[ib]){sb++;}
        if(answers[i] == c[ic]){sc++;}
        
        ia++;ib++;ic++;
        if(ia>=5){ia=0;}
        if(ib>=8){ib=0;}
        if(ic>=10){ic=0;}
    }
    int m = max(sa, max(sb,sc));
    
    vector<int> answer;
    if(sa==m){answer.push_back(1);}
    if(sb==m){answer.push_back(2);}
    if(sc==m){answer.push_back(3);}
    return answer;
}
