#include <iostream>
using namespace std;

int a;
int house[16][16];
long long dp[16][16][3]; // 0: 가로, 1: 세로, 2: 대각선

// 처음엔 dp+bfs로 풀려고 했으나, 그냥 dp만으로도 풀 수 있었음
int main() {
    cin >> a;

    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            cin >> house[i][j];

    dp[0][1][0] = 1; 

    for (int i = 0; i < a; i++) {
        for (int j = 2; j < a; j++) {
            if (house[i][j] == 1) continue;

            // 가로로 이동
            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

            // 세로로 이동
            if (i > 0)
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];

            // 대각선으로 이동
            if (i > 0 && house[i - 1][j] == 0 && house[i][j - 1] == 0)
                dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        }
    }

    cout << dp[a - 1][a - 1][0] + dp[a - 1][a - 1][1] + dp[a - 1][a - 1][2] << '\n';
    return 0;
}
