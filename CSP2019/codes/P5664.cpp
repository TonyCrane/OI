/*************************************************************
 *  > File Name        : P5664.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/25 12:37:48
 *  > Algorithm        : 
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
const int p = 110;
const int mod = 998244353;

int n, m, a[maxn][2010];
long long ans = 1, sum[maxn], dp[maxn][maxn + p];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = read();
            sum[i] += a[i][j];
            sum[i] %= mod;
        }
        ans *= (sum[i] + 1);
        ans %= mod;
    }
    dp[0][0 + p] = 1;
    for (int k = 1; k <= m; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = -i; j <= i; ++j) {
                dp[i][j + p] = dp[i - 1][j + p];
                dp[i][j + p] += dp[i - 1][j - 1 + p] * a[i][k];
                dp[i][j + p] %= mod;
                dp[i][j + p] += dp[i - 1][j + 1 + p] * (sum[i] - a[i][k]);
                dp[i][j + p] %= mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans -= dp[n][i + p];
            ans += mod;
            ans %= mod;
        }
    }
    printf("%lld\n", (ans - 1 + mod) % mod);
    return 0;
}