#include <string>
#include <vector>

using namespace std;
long long fibo[100000] = {0,1};
int solution(int n) {
    int answer = 0;
    for (int i=2; i<=n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= 1234567;
    }


    return fibo[n];
}
