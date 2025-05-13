#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005][3];
int dp[2][3]; // [100000][3] 설정 시 메모리 초과
int main() {
    int a;
    cin >> a;

    //입력
    for (int i = 0; i < a; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    //초기값 설정
    int mi = (int)1e9; int ma = 0;

    //최소값
    for (int i = 0; i < 3; i++) { dp[0][i] = arr[0][i]; }
    for (int i = 1; i < a; i++) {
        dp[1][0] = min(dp[0][0], dp[0][1]) + arr[i][0];
        dp[1][1] = min(dp[0][0], min(dp[0][1], dp[0][2])) + arr[i][1];
        dp[1][2] = min(dp[0][2], dp[0][1]) + arr[i][2];
        for (int i = 0; i < 3; i++) { dp[0][i] = dp[1][i]; } //한 칸 위로 올림
    }
    for (int i = 0; i < 3; i++) { mi = min(mi, dp[0][i]); }

    //최대값
    for (int i = 0; i < 3; i++) { dp[0][i] = arr[0][i]; }
    for (int i = 1; i < a; i++) {
        dp[1][0] = max(dp[0][0], dp[0][1]) + arr[i][0];
        dp[1][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + arr[i][1];
        dp[1][2] = max(dp[0][2], dp[0][1]) + arr[i][2];
        for (int i = 0; i < 3; i++) { dp[0][i] = dp[1][i]; } //한 칸 위로 올림
    }
    for (int i = 0; i < 3; i++) { ma = max(ma, dp[0][i]); }

    //결과
    cout << ma << " " << mi;

    return 0;
}
