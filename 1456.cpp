#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <climits>
using namespace std;

int number = 10000000; 
int primeNum[10000001];
set<long long> v;

void primeNumberSieve()
{
    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // 소수 출력
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0){}
            //printf("%d\n", primeNum[i]);
    }
}
int main()
{
    primeNumberSieve();
    for (int i = 2; i < 10000001; i++) {
        if (primeNum[i] != 0) {
            
            long long tmp = (long long)i * i;
            while (tmp < 100000000000000LL) {
                v.insert(tmp);
                tmp *= i;

                //다음에 i를 곱하면 long long 제한을 넘어가버리는 경우 고려(계산 스킵)
                if (tmp >= LLONG_MAX / i) { break; }
            }
        }
    }

    long long a, b;
    cin >> a >> b;
    int ans = 0;
    for (long long i : v) {
        if (i < a) { continue; }
        else if (i <= b) { ans++; }
    }
    cout << ans;
}