#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++) {
        q.push(progresses[i]);
    }
    int count = 1; int cur = 0;
    while (!q.empty()) {
        int ret = 0;
        while (q.front() + count * speeds[cur] >= 100 && !q.empty()) {
            q.pop(); ret++; cur++;
        }
        if (ret != 0) { answer.push_back(ret); }
        count++;
    }

    return answer;
}
