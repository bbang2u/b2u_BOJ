#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int x = 1; x <= r2; x++) {
        long long maxY = floor(sqrt((long long)r2 * r2 - (long long)x * x));
        long long minY = 0;
        if (x < r1) {
            minY = ceil(sqrt((long long)r1 * r1 - (long long)x * x));
        }
        answer += (maxY - minY + 1);
    }
    return answer * 4;
}
