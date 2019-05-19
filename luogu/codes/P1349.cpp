/*************************************************************
 *  > File Name        : P1349.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/19 12:05:52
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

typedef long long Matrix[2][2];
typedef long long Vector[2];

int sz, mod;

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

void transform(Vector d, Matrix A, Vector res) {
    Vector r;
    memset(r, 0, sizeof(r));
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            r[j] = (r[j] + d[i] * A[i][j]) % mod;
        }
    }
    memcpy(res, r, sizeof(r));
}

int main() {
    int p = read(), q = read(), a1 = read(), a2 = read(), n = read(), m = read();
    Vector F; Matrix A;
    F[0] = a2 % m; F[1] = a1 % m;
    A[0][0] = p % m; A[0][1] = 1; A[1][0] = q % m; A[1][1] = 0;
    sz = 2; mod = m;
    matrix_pow(A, n - 1, A);
    transform(F, A, F);
    printf("%lld\n", F[1]);
    return 0;
}