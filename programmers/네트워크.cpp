#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n);

    for (int i = 0; i < n; i++) {
        if (visited[i]) { continue; }
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            visited[cur] = true;
            q.pop();
            for (int j = 0; j < n; j++) {
                if (computers[cur][j] == 1 && !visited[j]) {
                    q.push(j);
                }
            }
        }
        answer++;
    }

    return answer;
}
