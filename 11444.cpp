#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

struct Matrix {
    ll a, b, c, d;
    Matrix(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}
};

Matrix multiply(const Matrix& x, const Matrix& y) {
    return Matrix(
        (x.a * y.a % MOD + x.b * y.c % MOD) % MOD,
        (x.a * y.b % MOD + x.b * y.d % MOD) % MOD,
        (x.c * y.a % MOD + x.d * y.c % MOD) % MOD,
        (x.c * y.b % MOD + x.d * y.d % MOD) % MOD
    );
}

Matrix power(Matrix m, ll n) {
    Matrix result(1, 0, 0, 1);
    while (n > 0) {
        if (n % 2 == 1) result = multiply(result, m);
        m = multiply(m, m);
        n /= 2;
    }
    return result;
}

//처음엔 
//long long ans = (long long)((pow_custom((1 + sq5) / 2, a, 1000000007) - pow_custom((1 - sq5) / 2, a, 1000000007)) / sq5) % 1000000007
//위 식처럼 비네 공식을 활용해서 풀고자 했으나, 부동 소수점 오차로 인해 실패. 행렬곱을 이용한 풀이로 전환
int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    Matrix base(1, 1, 1, 0);
    Matrix result = power(base, n - 1);
    cout << result.a; // F(n)
}
