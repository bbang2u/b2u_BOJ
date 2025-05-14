#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int arr[100005][3];
int dp[2][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin >> a;
    priority_queue<int> pq;
    while (a--) {
        int b; cin >> b;
        if (b == 0) {
            if (pq.empty()) { cout << 0 << "\n"; }//endl 사용시 시간초과
            else { cout << pq.top() << "\n"; pq.pop(); }
        }
        else { pq.push(b); }
    }

    return 0;
}
