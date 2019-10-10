/*************************************************************
 *  > File Name        : P2331.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/10 21:06:37
 *  > Algorithm        : DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;
const int maxk = 20;

int n, m, _k, s[maxn], sum[maxn], dp[maxn][maxk], f[maxn][maxn][maxk];

int main() {
    n = read(); m = read(); _k = read();
    if (m == 1) {
        for (int i = 1; i <= n; ++i) {
            int x = read();
            s[i] = s[i - 1] + x;
        }
        for (int k = 1; k <= _k; ++k) {
            for (int i = 1; i <= n; ++i) {
                dp[i][k] = dp[i - 1][k];
                for (int j = 0; j < i; ++j) {
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + s[i] - s[j]);
                }
            }
        }
        printf("%d\n", dp[n][_k]);
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read();
        s[i] = s[i - 1] + x; sum[i] = sum[i - 1] + y;
    }
    for (int k = 1; k <= _k; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                f[i][j][k] = max(f[i - 1][j][k], f[i][j - 1][k]);
                for (int l = 0; l < i; ++l) {
                    f[i][j][k] = max(f[i][j][k], f[l][j][k - 1] + s[i] - s[l]);
                }
                for (int l = 0; l < j; ++l) {
                    f[i][j][k] = max(f[i][j][k], f[i][l][k - 1] + sum[j] - sum[l]);
                }
                if (i == j) {
                    for (int l = 0; l < i; ++l) {
                        f[i][j][k] = max(f[i][j][k], f[l][l][k - 1] + s[i] - s[l] + sum[j] - sum[l]);
                    }
                }
            }
        }
    }
    printf("%d\n", f[n][n][_k]);
    return 0;
}