#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

bool r_visited[4][4];
bool b_visited[4][4];
vector<vector<int>> g_maze;

int rd1, rd2, bd1, bd2;

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n) return false;
    if (g_maze[x][y] == 5) return false; 
    return true;
}

int solve(int r1, int r2, int b1, int b2, int turn) {

    if (r1 == rd1 && r2 == rd2 && b1 == bd1 && b2 == bd2) {
        return turn;
    }

    int ans = 100000;

    vector<pair<int, int>> r_moves, b_moves;

    if (r1 == rd1 && r2 == rd2) {
        r_moves.push_back({0, 0}); 
    } else {
        for (int i = 0; i < 4; i++) r_moves.push_back({dx[i], dy[i]});
    }

    if (b1 == bd1 && b2 == bd2) {
        b_moves.push_back({0, 0});
    } else {
        for (int i = 0; i < 4; i++) b_moves.push_back({dx[i], dy[i]});
    }

    for (auto r_dir : r_moves) {
        for (auto b_dir : b_moves) {
            int nr1 = r1 + r_dir.first;
            int nr2 = r2 + r_dir.second;
            int nb1 = b1 + b_dir.first;
            int nb2 = b2 + b_dir.second;

            if (!isValid(nr1, nr2) || !isValid(nb1, nb2)) continue;


            if ((r1 != rd1 || r2 != rd2) && r_visited[nr1][nr2]) continue;
            if ((b1 != bd1 || b2 != bd2) && b_visited[nb1][nb2]) continue;

            if (nr1 == nb1 && nr2 == nb2) continue;


            if (nr1 == b1 && nr2 == b2 && nb1 == r1 && nb2 == r2) continue;

            bool r_check = false;
            bool b_check = false;

            if (r1 != rd1 || r2 != rd2) {
                r_visited[nr1][nr2] = true;
                r_check = true;
            }
            if (b1 != bd1 || b2 != bd2) {
                b_visited[nb1][nb2] = true;
                b_check = true;
            }

            ans = min(ans, solve(nr1, nr2, nb1, nb2, turn + 1));


            if (r_check) r_visited[nr1][nr2] = false;
            if (b_check) b_visited[nb1][nb2] = false;
        }
    }

    return ans;
}

int solution(vector<vector<int>> maze) {
    g_maze = maze;
    m = maze.size();
    n = maze[0].size();
    
    int r1, r2, b1, b2;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == 1) { r1 = i; r2 = j; }
            else if (maze[i][j] == 2) { b1 = i; b2 = j; }
            else if (maze[i][j] == 3) { rd1 = i; rd2 = j; }
            else if (maze[i][j] == 4) { bd1 = i; bd2 = j; }
        }
    }

    r_visited[r1][r2] = true;
    b_visited[b1][b2] = true;

    int result = solve(r1, r2, b1, b2, 0);

    return (result == 100000) ? 0 : result;
}
