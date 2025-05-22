#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int num,a, b, c, d, e;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int n;
vector<pair<int,int>> store;
vector<int> answer;
int grid[50][50];

int chickenum = (int)1e9;

bool isinside(int x, int y) { return x >= 0 && x < a && y >= 0 && y < a; }

void Calc(vector<int> ans) {
    int tmpgrid[50][50];
    

    queue<pair<int, pair<int, int>>> q;
    vector<pair<int,int>> houses;

    for (int i = 0; i < 50; i++) { 
        for (int j = 0; j < 50; j++) { 
            tmpgrid[i][j] = grid[i][j]; 
            if (grid[i][j] == 2) { tmpgrid[i][j] = 0; }
            if (grid[i][j] == 1) { houses.push_back({i,j}); }
        } 
    }

    for (int num : ans) {
        tmpgrid[store[num - 1].first][store[num - 1].second] = 2;
    }

    int curchickenum = 0;
    //거리 체크, 괜히 bfs 쓰려고 하면 시간초과 남
    for (pair<int,int> house : houses) {
        int dist = (int)1e9;
        for (int num : ans) {
            dist = min(dist, abs(house.first - store[num - 1].first) + abs(house.second - store[num - 1].second));
        }
        curchickenum += dist;
    }
    chickenum = min(chickenum, curchickenum);
}
void Choose(int curr_num, int previous) {
    if (curr_num == n + 1) {

        Calc(answer);
        return;
    }

    for (int i = 1; i <= num; i++) {
        if (i <= previous) { continue; }
        answer.push_back(i);
        Choose(curr_num + 1, i);
        answer.pop_back();

    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    num = 0;
    cin >> a >> n;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) { 
            cin >> grid[i][j]; 
            if (grid[i][j] == 2) {
                store.push_back({ i,j });
                num++;
            }
        }
    }

    Choose(1, 0);

    cout << chickenum;
    return 0;
}
