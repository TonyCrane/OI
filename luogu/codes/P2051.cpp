/*************************************************************
 *  > File Name        : P2051.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/09 21:09:56
 *  > Algorithm        : DP
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
const int mod  = 9999973;

long long n, m, dp[maxn][maxn][maxn], ans;

inline long long C2(long long x) {
    return ( x * (x - 1) / 2 ) % mod;
}

int main() {
    n = read(); m = read();
    dp[0][0][0] = 1;
    for (long long i = 1; i <= n; ++i) {
        for (long long j = 0; j <= m; ++j) {
            for (long long k = 0; k <= m - j; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k >= 1) dp[i][j][k] += dp[i - 1][j + 1][k - 1] * (j + 1);
                if (j >= 1) dp[i][j][k] += dp[i - 1][j - 1][k] * (m - j - k + 1);
                if (k >= 2) dp[i][j][k] += dp[i - 1][j + 2][k - 2] * C2(j + 2);
                if (k >= 1) dp[i][j][k] += dp[i - 1][j][k - 1] * j * (m - j - k + 1);
                if (j >= 2) dp[i][j][k] += dp[i - 1][j - 2][k] * C2(m - j - k + 2);
                dp[i][j][k] %= mod;
            }
        }
    }
    for (long long i = 0; i <= m; ++i) {
        for (long long j = 0; j <= m; ++j) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}