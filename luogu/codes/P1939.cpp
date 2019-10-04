/*************************************************************
 *  > File Name        : P1939.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/04 16:02:12
 *  > Algorithm        : Matrix
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5;
const int mod  = 1000000007;
const int sz   = 3;

typedef long long Matrix[maxn][maxn];

void matrix_mul(Matrix A, Matrix B, Matrix res) {
    Matrix C;
    memset(C, 0, sizeof(C));
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < sz; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    memcpy(res, C, sizeof(C));
}

void matrix_pow(Matrix A, int n, Matrix res) {
    Matrix a, r;
    memcpy(a, A, sizeof(a));
    memset(r, 0, sizeof(r));
    for (int i = 0; i < sz; ++i) r[i][i] = 1;
    while (n) {
        if (n & 1) matrix_mul(r, a, r);
        n >>= 1;
        matrix_mul(a, a, a);
    }
    memcpy(res, r, sizeof(r));
}

Matrix ans, a;

int main() {
    int T = read();
    while (T--) {
        int n = read();
        if (n <= 3) {
            puts("1");
            continue;
        }
        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                a[i][j] = 0;
            }
        }
        a[0][0] = a[0][2] = a[1][0] = a[2][1] = 1;
        matrix_pow(a, n, ans);
        printf("%lld\n", ans[1][0]);
    }
}