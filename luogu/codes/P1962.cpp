/*************************************************************
 *  > File Name        : P1962.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/14 20:07:17
 *  > Algorithm        : Matrix
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

const LL mod = 1000000007;

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

int main() {
    LL n = read();
    Base.mat[0][0] = 1; Base.mat[0][1] = 1;
    Base.mat[1][0] = 1; Base.mat[1][1] = 0;
    Fib.mat[0][0] = 1; Fib.mat[0][1] = 1;
    if (n > 3) Matrix_pow(n - 2);
    printf("%lld\n", Fib.mat[0][0] % mod);
    return 0;
}