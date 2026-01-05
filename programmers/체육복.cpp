#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> count(n);
    for(int i=0;i<n;i++){
        count[i] = 1;
    }
    for(int i : lost){count[i - 1]--;}
    for(int i : reserve){count[i - 1]++;}
    for(int i=0;i<n;i++){
         
            if(i>0){
                if(count[i-1]==2 && count[i] == 0){
                    count[i] = 1;
                    count[i-1]=1;
                }
            }
            if(i<n-1){
                if(count[i+1]==2 && count[i] == 0){
                    count[i] = 1;
                    count[i+1] = 1;
                }
            }
        
        if(count[i]>0){answer++;}
    }
    return answer;
}
