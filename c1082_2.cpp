/*************************************************************
 *  > File Name        : c1082_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/31 21:25:53
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long Matrix[maxn][maxn];

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5010;

int m, p, 

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

int phi(int n) {
    int m = (int)sqrt(n + 0.5); int ans = n;
    for (int i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

