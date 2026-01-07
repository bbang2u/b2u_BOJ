#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500];
    dp[0][0] = triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            int left = 0; int right = 0;
            if(j != 0){
                left = dp[i - 1][j - 1];
            }
            if(j != triangle[i].size() - 1){
                right = dp[i - 1][j];
            }
            dp[i][j] = triangle[i][j] + max(left, right);
        }
    }
    
    for(int i : dp[triangle.size() - 1]){
        answer = max(answer, i);
    }
    return answer;
}
