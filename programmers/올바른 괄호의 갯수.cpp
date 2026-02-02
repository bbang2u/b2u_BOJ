#include <string>
#include <vector>
#include <set>

using namespace std;
set<string> s;
int l = 0;
void make(int open, int close, string cur) {
    if (open + close == l) {
        s.insert(cur);
        return;
    }
    if (open > close) {
        if (open + 1 <= l / 2) {
            make(open + 1, close, cur + "(");
        }
        if (close + 1 <= l / 2) {
            make(open, close + 1, cur + ")");
        }
    }
    else {
        if (open + 1 <= l / 2) {
            make(open + 1, close, cur + "(");
        }
    }
}

int solution(int n) {
    l = n * 2;
    make(1, 0, "(");
    return s.size();
}
