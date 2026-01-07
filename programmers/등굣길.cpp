#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[100][100];
int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i=0;i<100;i++){for(int j=0;j<100;j++){dp[i][j] = 0;}}
    int answer = 0;
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }
    
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0 || dp[i][j] == -1){continue;}
            
            if(i == 0){
                if(dp[i][j - 1] != -1){
                    dp[i][j] = dp[i][j - 1];
                }
            }
            else if (j == 0){
                if(dp[i - 1][j] != -1){
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else{
                if(dp[i][j - 1] != -1){
                    dp[i][j] += dp[i][j - 1];
                }
                if(dp[i - 1][j] != -1){
                    dp[i][j] += dp[i - 1][j];
                }
            }
            dp[i][j]%=1000000007;
        }
    }
    return dp[n - 1][m - 1];
}
