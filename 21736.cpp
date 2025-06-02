#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;
char arr[600][600];
bool visited[600][600] = { false };
int a, b;
bool isinside(int n, int m) { return n >= 0 && n < a && m >= 0 && m < b; }
int dx[4] = { 0,0,1,-1 }; int dy[4] = { 1,-1,0,0 };
int main() {
    cin >> a >> b;
    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < a; i++) {
        string s; cin >> s;
        for (int j = 0; j < b; j++) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'I') { q.push({ i,j }); }
        }
    }
    int x = q.front().first; int y = q.front().second;
    visited[x][y] = true;
    while (!q.empty()) {
        int x = q.front().first; int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i]; int ny = y + dy[i];
            if (isinside(nx, ny)) {
                if (!visited[nx][ny] && arr[nx][ny]!='X') {
                    if (arr[nx][ny] == 'P') { 
                        ans++; 
                    }
                    q.push({ nx, ny });
                    visited[nx][ny] = true;
                }
            }
        }
    }
    if (ans == 0) { cout << "TT"; }
    else { cout << ans; }
    
    return 0;
}
