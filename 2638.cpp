#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int grid[100][100];

int a, b;
bool isinside(int n, int m) { return n >= 0 && n < a && m >= 0 && m < b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> grid[i][j];
        }
    }
    int turns = 0;
    
    while (true) {
        bool fin = true;
        bool outside[100][100];  bool visited[100][100];

        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++) {
                outside[i][j] = false; visited[i][j] = false;
            }
                

        outside[0][0] = true;
        

        queue<pair<int, int>> q;
        q.push({ 0, 0 });

        //치즈 바깥의 빈 공간 확인
        while (!q.empty()) {
            int curA = q.front().first; int curB = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int na = curA + dx[i]; int nb = curB + dy[i];
                if (isinside(na, nb)) {
                    if (grid[na][nb] == 0 && !visited[na][nb]) {
                        outside[na][nb] = true;
                        visited[na][nb] = true;
                        q.push({ na,nb });
                    }
                }
            }

        }

        //바깥과 맞닿은 치즈 확인
        vector<pair<int, int>> disappear;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (grid[i][j] == 1) {
                    int adj = 0;
                    for (int k = 0; k < 4; k++) {
                        int na = i + dx[k]; int nb = j + dy[k];
                        if (isinside(na, nb)) {
                            if (outside[na][nb]) {
                                adj++;
                            }
                        }
                    }
                    if (adj >= 2) { disappear.push_back({ i,j }); }
                }
            }
        }

        for (pair<int, int> i : disappear) { grid[i.first][i.second] = 0; }

        
        //치즈가 전부 없어졌는지 확인
        turns++;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (grid[i][j] == 1) { fin = false; }
            }
        }
        if (fin) { break; }
    }

    cout << turns;
    return 0;
}
