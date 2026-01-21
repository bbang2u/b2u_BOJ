#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
    }
    sort(priorities.begin(), priorities.end(), cmp);
    int count = 1; int idx = 0;
    while (true) {
        if (q.front().first != priorities[idx]) {
            q.push(q.front());
        }
        else {
            if (q.front().second == location) { break; }
            count++; idx++;
        }
        q.pop();
    }
    int answer = count;
    return answer;
}
