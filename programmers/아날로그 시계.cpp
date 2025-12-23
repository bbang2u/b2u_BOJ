#include <string>
#include <vector>

using namespace std;

int getCount(int h, int m, int s) {
    int total_sec = h * 3600 + m * 60 + s;

    int sm_count = (long long)total_sec * 59 / 3600;

    int sh_count = (long long)total_sec * 719 / 43200;

    int total = sm_count + sh_count;

    if (total_sec >= 43200) {
        total -= 1;
    }
    
    return total;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = getCount(h2, m2, s2) - getCount(h1, m1, s1);
    

    if (h1 == 0 && m1 == 0 && s1 == 0) {
        answer += 1;
    }
    if (h1 == 12 && m1 == 0 && s1 == 0) {
        answer += 1;
    }
    
    return answer;
}
