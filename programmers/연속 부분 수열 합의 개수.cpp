#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> s;
    for (int i = 0; i < elements.size(); i++) {
        int sum = 0;
        for (int j = 0; j < elements.size(); j++) {
            int idx = i + j;
            if (idx >= elements.size()) { idx -= elements.size(); }
            sum += elements[idx];
            s.insert(sum);
        }
    }
    return s.size();
}
