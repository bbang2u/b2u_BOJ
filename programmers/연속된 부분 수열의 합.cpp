#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0; int end = 0;
    int cur = sequence[0];
    int startans = -1; int endans = -1; int lengthans = -1;
    while(true){
        
        if(cur > k){
            cur-=sequence[start]; start++; 
        }
        else if(cur < k){
            if(end == sequence.size() - 1){break;}
            end++;  cur+=sequence[end];
        }
        
        if(cur == k){
            if(lengthans == -1){
                lengthans = end - start + 1;
                startans = start; endans = end;
            }
            else if (end - start + 1 < lengthans){
                lengthans = end - start + 1;
                startans = start; endans = end;
            }
            cur-=sequence[start]; start++; 
        }
    }
    answer.push_back(startans);
    answer.push_back(endans);
    return answer;
}
