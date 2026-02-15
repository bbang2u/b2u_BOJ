#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;
    for (int i : tangerine) {
        m[i]++;
    }
    vector<pair<int, int>> v;
    for (auto iter : m) {
        v.push_back({ iter.first, iter.second });
    }
    sort(v.begin(), v.end(), cmp);

    for (auto i : v) {
        k -= i.second;
        answer++;
        if (k <= 0) { break; }
    }

    return answer;
}
