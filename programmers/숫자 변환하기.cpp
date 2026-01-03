#include <string>
#include <vector>
#include <queue>

using namespace std;
int visited[1000001];
int solution(int x, int y, int n) {
    int answer = 0;
    for (int i = 0; i < 1000001; i++) { visited[i] = -1; }

    queue<pair<int, int>> q;
    q.push({ x, 0 });
    while (!q.empty()) {
        
        int cur = q.front().first; int curtime = q.front().second;
        q.pop();

        if (visited[cur] != -1 && visited[cur] <= curtime) { continue; }
        visited[cur] = curtime;

        int plus = cur + n;
        int m2 = cur * 2;
        int m3 = cur * 3;

        if (plus > 0 && plus <= 1000000) {
            q.push({ plus, curtime + 1 });
        }
        if (m2 > 0 && m2 <= 1000000) {
            q.push({ m2, curtime + 1 });
        }
        if (m3 > 0 && m3 <= 1000000) {
            q.push({ m3, curtime + 1 });
        }
    }

    return visited[y];
}
