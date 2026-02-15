#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<int> q1; queue<int> q2;
    long long q1sum = 0;
    long long q2sum = 0;
    for (int i : queue1) { q1.push(i); q1sum += i; }
    for (int i : queue2) { q2.push(i); q2sum += i; }

    for (int i = 0; i < queue1.size() * 3; i++) {
        if (q1sum > q2sum) {
            q1sum -= q1.front();
            q2.push(q1.front());
            q2sum += q1.front();
            q1.pop();
        }
        else if (q1sum < q2sum) {
            q2sum -= q2.front();
            q1.push(q2.front());
            q1sum += q2.front();
            q2.pop();
        }
        else {
            return i;
        }
    }

    return answer;
}
