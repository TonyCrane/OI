/*************************************************************
 *  > File Name        : c1082_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/31 21:25:53
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 5010;

LL m, p, n, q, mod;

LL pow_mod(LL a, LL p){
    LL res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % q;
        a = 1LL * a * a % q;
        p >>= 1;
    }
    return res;
}

struct Matrix {
    LL mat[2][2];
    Matrix() { memset(mat, 0, sizeof(mat)); }
    Matrix operator * (const Matrix& a) const {
        Matrix res; memset(res.mat, 0, sizeof(res.mat));
        for (LL i = 0; i < 2; ++i) {
            for (LL j = 0; j < 2; ++j) {
                for (LL k = 0; k < 2; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
}Base, Fib;

void Matrix_pow(LL pow) {
    while (pow) {
        if (pow & 1) Fib = Fib * Base;
        Base = Base * Base;
        pow >>= 1;
    }
}

LL phi(LL n) {
    LL m = (LL)sqrt(n + 0.5); LL ans = n;
    for (LL i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main() {
    m = read(); p = read();
    while (m--) {
        n = read(); q = read();
        mod = phi(q);
        Base.mat[0][0] = 1; Base.mat[0][1] = 1;
        Base.mat[1][0] = 1; Base.mat[1][1] = 0;
        Fib.mat[0][0] = Fib.mat[0][1] = 1;
        if (n >= 3) Matrix_pow(n - 2);
        printf("%lld\n", pow_mod(p, Fib.mat[0][0] + mod));
    }
    return 0;
}