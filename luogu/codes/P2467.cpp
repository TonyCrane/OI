/*************************************************************
 *  > File Name        : P2467.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/10 21:19:23
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

const int maxn = 5010;

int n, mod, dp[maxn][2], ans;

int main() {
    n = read(); mod = read();
    dp[2][0] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 2; j <= i; ++j) {
            dp[j][i & 1] = dp[j - 1][i & 1] + dp[i - j + 1][(i - 1) & 1];
            dp[j][i & 1] %= mod;
        }
    }
    for (int j = 2; j <= n; ++j) {
        ans += dp[j][n & 1];
        ans %= mod;
    }
    printf("%d\n", (ans << 1) % mod);
    return 0;
}