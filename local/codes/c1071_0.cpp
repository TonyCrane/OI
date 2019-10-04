/*************************************************************
 *  > File Name        : c1071_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/03 12:42:42
 *  > Algorithm        : Matrix
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0; long long f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const long long maxn = 11;
const long long mod  = 1000000007;
const long long sz   = 11;

typedef long long Matrix[maxn][maxn];

void matrix_mul(Matrix A, Matrix B, Matrix res) {
    Matrix C;
    memset(C, 0, sizeof(C));
    for (long long i = 0; i < sz; ++i) {
        for (long long j = 0; j < sz; ++j) {
            for (long long k = 0; k < sz; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod + mod) % mod;
            }
        }
    }
    memcpy(res, C, sizeof(C));
}

void matrix_pow(Matrix A, long long n, Matrix res) {
    Matrix a, r;
    memcpy(a, A, sizeof(a));
    memset(r, 0, sizeof(r));
    for (long long i = 0; i < sz; ++i) r[i][i] = 1;
    while (n) {
        if (n & 1) matrix_mul(r, a, r);
        n >>= 1;
        matrix_mul(a, a, a);
    }
    memcpy(res, r, sizeof(r));
}

Matrix ans, base;

const long long tab[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main() {
    long long T = read();
    while (T--) {
        memset(ans, 0, sizeof(ans));
        memset(base, 0, sizeof(base));
        long long n = read();
        if (n <= 9) {
            printf("%lld\n", tab[n]);
            continue;
        }
        for (long long i = 1; i < sz; ++i) {
            base[i][i - 1] = 1;
        }
        base[0][0] = base[0][1] = 1;
        base[0][10] = -1;
        matrix_pow(base, n - 10, base);
        ans[0][0] = 88;
        for (long long i = 1; i < sz; ++i) {
            ans[i][0] = tab[10 - i];
        }
        matrix_mul(base, ans, ans);
        printf("%lld\n", ans[0][0]);
    }
    return 0;
}

/**
 * 1  1  0  ... -1
 * 1  0  0  ...  0
 * 0  1  0  ...  0
 * 0  0  1  ...  0
 * ...............
 * ...........1  0
 **/