/*************************************************************
 *  > File Name        : P3390.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/14 21:30:01
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

const LL mod = 1e9 + 7;

LL n;

struct Matrix {
    LL mat[110][110];
    Matrix() { memset(mat, 0, sizeof(mat)); }
    Matrix operator * (const Matrix& a) const {
        Matrix res; memset(res.mat, 0, sizeof(res.mat));
        for (LL i = 0; i < n; ++i) {
            for (LL j = 0; j < n; ++j) {
                for (LL k = 0; k < n; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
}Base, A;

void Matrix_pow(LL pow) {
    while (pow) {
        if (pow & 1) A = A * Base;
        Base = Base * Base;
        pow >>= 1;
    }
}

int main() {
    n = read(); LL k = read();
    for (LL i = 0; i < n; ++i) {
        for (LL j = 0; j < n; ++j) {
            Base.mat[i][j] = read();
        }
    }
    for (LL i = 0; i < n; ++i) A.mat[i][i] = 1;
    Matrix_pow(k);
    for (LL i = 0; i < n; ++i) {
        for (LL j = 0; j < n; ++j) {
            printf("%lld ", A.mat[i][j] % mod);
        }
        puts("");
    }
    return 0;
}