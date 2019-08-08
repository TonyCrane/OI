/*************************************************************
 *  > File Name        : 1127.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/08 16:55:46
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

const int maxn = 200010;
const int inf  = 0x3f3f3f3f;

int dp[maxn], vis[maxn], n, m;
vector<int> G[maxn];

void solve_max(int u, int dep) {
    if (dep == 1) dp[u] = inf;
    else dp[u] = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        vis[u] = 1;
        solve_max(v, dep ^ 1);
        if (dep == 1) dp[u] = min(dp[u], dp[v]);
        else dp[u] += dp[v];
    }
    if (!vis[u]) {
        dp[u] = 1;
        m++;
    }
}

void solve_min(int u, int dep) {
    if (dep == 1) dp[u] = 0;
    else dp[u] = inf;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        vis[u] = 1;
        solve_min(v, dep ^ 1);
        if (dep == 1) dp[u] += dp[v];
        else dp[u] = min(dp[u], dp[v]);
    }
    if (!vis[u]) {
        dp[u] = 1;
    }
}

int main() {
    n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
    }
    solve_max(1, 1);
    printf("%d ", m - dp[1] + 1);
    solve_min(1, 1);
    printf("%d\n", dp[1]);
    return 0;
}