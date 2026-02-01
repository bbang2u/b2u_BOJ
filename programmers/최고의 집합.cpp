#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int a = s / n;
    if(a == 0){return {-1};}
    int b = s % n;
    for(int i=0;i<n;i++){
        if(b != 0){
            answer.push_back(a + 1);
            b--;
        }
        else{
            answer.push_back(a);
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
