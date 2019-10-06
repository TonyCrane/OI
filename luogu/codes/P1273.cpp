/*************************************************************
 *  > File Name        : P1273.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/06 20:23:44
 *  > Algorithm        : 树形DP+分组
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 3010;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int n, m, money[maxn];
int dp[maxn][maxn];

int DP(int u) {
    if (u >= n - m + 1) {
        dp[u][1] = money[u];
        return 1;
    }
    int siz = 0, cnt;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        cnt = DP(e.to); siz += cnt;
        for (int j = siz; j; --j) {
            for (int k = 1; k <= cnt; ++k) {
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[e.to][k] - e.val);
            } 
        }
    }
    return siz;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n - m; ++i) {
        int k = read();
        for (int j = 1; j <= k; ++j) {
            int v = read(), w = read();
            add(i, v, w);
        }
    }
    for (int i = n - m + 1; i <= n; ++i) {
        money[i] = read();
    }
    memset(dp, 0xc0, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
    }
    DP(1);
    for (int i = m; i; --i) {
        if (dp[1][i] >= 0) {
            printf("%d\n", i);
            return 0;
        }
    }
}