/*************************************************************
 *  > File Name        : P2577.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/07 12:54:58
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

const int maxn = 210;

struct Node {
    int a, b;
    bool operator < (const Node& c) const {
        return b > c.b;
    }
}peo[maxn];

int n, dp[maxn][maxn * maxn], sum[maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        peo[i].a = read();
        peo[i].b = read();
    }
    sort(peo + 1, peo + 1 + n);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + peo[i].a;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum[i]; ++j) {
            if (j >= peo[i].a) dp[i][j] = min(dp[i][j], max(dp[i - 1][j - peo[i].a], j + peo[i].b));
            dp[i][j] = min(dp[i][j], max(dp[i - 1][j], sum[i] - j + peo[i].b));
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= sum[n]; ++i) {
        ans = min(ans, dp[n][i]);
    }
    printf("%d\n", ans);
}