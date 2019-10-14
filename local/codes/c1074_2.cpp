/*************************************************************
 *  > File Name        : c1074_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/12 16:38:06
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

const int maxn = 110;
const int mod  = 1e9 + 7;

long long n, m, K;

struct Matrix {
    long long mat[maxn][maxn];
    Matrix operator * (const Matrix& a) const {
        Matrix res; memset(res.mat, 0, sizeof(res.mat));
        for (long long i = 1; i <= n; ++i) {
            for (long long j = 1; j <= n; ++j) {
                for (long long k = 1; k <= n; ++k) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * a.mat[k][j]) % mod;
                }
            }
        }
        return res;
    }
}G;

Matrix mat_pow(Matrix a, long long pow) {
    Matrix res; memset(res.mat, 0, sizeof(res.mat));
    for (long long i = 1; i <= n; ++i) res.mat[i][i] = 1;
    while (pow) {
        if (pow & 1) res = a * res;
        a = a * a;
        pow >>= 1;
    }
    return res;
}

int main() {
    n = read(); m = read(); K = read();
    for (long long i = 1; i <= m; ++i) {
        long long u = read(), v = read();
        G.mat[u][v] = 1;
    }
    G = mat_pow(G, K);
    for (long long i = 1; i <= n; ++i) {
        printf("%lld ", G.mat[1][i]);
    }
    return 0;
}