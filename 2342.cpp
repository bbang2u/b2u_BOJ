#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a;
vector<int> v;
int dp[100000][5][5];

int main() {
    for (int i = 0; i < 100000; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) { dp[i][j][k] = (int)1e8; }
        }
    }
    int mi = (int)1e9;
    //dp[0][0][0] = 0;
    cin >> a; if (a == 0) { cout << 0;return 0; }
    dp[0][a][0] = 2; dp[0][0][a] = 2;
    int i = 0;
    

    for(i = 1;i<100000;i++){
        cin >> a; if (a == 0) { break; }
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (k == 0) { //중앙에서 이동
                    dp[i][a][j] = min(dp[i - 1][k][j] + 2, dp[i][a][j]);
                    dp[i][j][a] = min(dp[i - 1][j][k] + 2, dp[i][j][a]);
                }
                else if (abs(k - a) == 2) { //반대편으로 이동
                    dp[i][a][j] = min(dp[i - 1][k][j] + 4, dp[i][a][j]);
                    dp[i][j][a] = min(dp[i - 1][j][k] + 4, dp[i][j][a]);
                }
                else if (k == a) { //같은 위치에서 한번 더 누름
                    dp[i][a][j] = min(dp[i - 1][k][j] + 1, dp[i][a][j]);
                    dp[i][j][a] = min(dp[i - 1][j][k] + 1, dp[i][j][a]);
                }
                else { // 인접한 칸으로 이동
                    dp[i][a][j] = min(dp[i - 1][k][j] + 3, dp[i][a][j]);
                    dp[i][j][a] = min(dp[i - 1][j][k] + 3, dp[i][j][a]);
                }
            }
            //두 발이 같은 위치에 있을 수 없음
            dp[i][j][j] = (int)1e9;
        }

    }

    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
            mi = min(dp[i - 1][j][k], mi);
        }
    }
    cout << mi;
    return 0;
}
