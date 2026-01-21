#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int same = 1; int diff = 0;
    char start = s[0];
    int idx = 1;
    while (idx < s.length()) {
        if (s[idx] == start) { same++; }
        else { diff++; }

        if (same == diff) {
            same = 1; diff = 0;
            if(idx < s.length() - 1){answer++;}
            start = s[++idx];
        }
        idx++;
    }
    return answer + 1;
}
