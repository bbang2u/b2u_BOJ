#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005][3];
int dp[2][3]; // [100000][3] ���� �� �޸� �ʰ�
int main() {
    int a;
    cin >> a;

    //�Է�
    for (int i = 0; i < a; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    //�ʱⰪ ����
    int mi = (int)1e9; int ma = 0;

    //�ּҰ�
    for (int i = 0; i < 3; i++) { dp[0][i] = arr[0][i]; }
    for (int i = 1; i < a; i++) {
        dp[1][0] = min(dp[0][0], dp[0][1]) + arr[i][0];
        dp[1][1] = min(dp[0][0], min(dp[0][1], dp[0][2])) + arr[i][1];
        dp[1][2] = min(dp[0][2], dp[0][1]) + arr[i][2];
        for (int i = 0; i < 3; i++) { dp[0][i] = dp[1][i]; } //�� ĭ ���� �ø�
    }
    for (int i = 0; i < 3; i++) { mi = min(mi, dp[0][i]); }

    //�ִ밪
    for (int i = 0; i < 3; i++) { dp[0][i] = arr[0][i]; }
    for (int i = 1; i < a; i++) {
        dp[1][0] = max(dp[0][0], dp[0][1]) + arr[i][0];
        dp[1][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + arr[i][1];
        dp[1][2] = max(dp[0][2], dp[0][1]) + arr[i][2];
        for (int i = 0; i < 3; i++) { dp[0][i] = dp[1][i]; } //�� ĭ ���� �ø�
    }
    for (int i = 0; i < 3; i++) { ma = max(ma, dp[0][i]); }

    //���
    cout << ma << " " << mi;

    return 0;
}
