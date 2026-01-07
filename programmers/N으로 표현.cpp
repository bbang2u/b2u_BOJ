#include <string>
#include <vector>
#include <queue>
using namespace std;
int calc(int N, int num){
    int tmp = N;
    for(int i=1;i<num;i++){
        tmp *= 10;
        tmp += N;
    }
    return tmp;
}
int solution(int N, int number) {
    int answer = -1;
    vector<int> dp[9];
    dp[1].push_back(N);
    
    dp[2].push_back(calc(N,2));
    dp[2].push_back(N * N);
    dp[2].push_back(N / N);
    dp[2].push_back(N + N);
    
    for(int i=3;i<=8;i++){
        for(int j=1;j<i;j++){
            dp[i].push_back(calc(N,i));
            for(int k : dp[j]){
                for(int l : dp[i - j]){
                    dp[i].push_back(k * l);
                    dp[i].push_back(k + l);
                    if(l != 0){
                        dp[i].push_back(k / l);
                    }
                    dp[i].push_back(k - l);
                }
            }
        }
    }
    for(int i=1;i<=8;i++){
        for(int j : dp[i]){
            if(j == number){
                return i;
            }
        }
    }
    
    
    return answer;
}
