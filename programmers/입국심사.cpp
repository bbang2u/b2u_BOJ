#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(long long n, long long mid, vector<int> times) {
    for (int i : times) {
        n -= (mid / i);
    }
    return n <= 0;
}

long long solution(int n, vector<int> times) {
    long long answer = 100000000000000;
    long long left = 0;
    long long right = 100000000000000;
    long long mid = -1;
    while (left < right) {
        mid = (left + right) / 2;
        if (solve(n, mid, times)) {
            answer = min(answer, mid);
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }


    return answer;
}
