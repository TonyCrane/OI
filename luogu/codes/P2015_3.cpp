/*************************************************************
 *  > File Name        : P2015_3.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/18 12:59:16
 *  > Algorithm        : [DP]Tree
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

int n, q, dp[maxn][maxn];

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w) : from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

void DP(int u, int fa) {
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == fa) continue;
        DP(e.to, u);
        for (int j = q; j >= 0; j--) {
            for (int k = 0; k < j; ++k) {
                dp[u][j] = max(dp[u][j], dp[e.to][k] + dp[u][j - k - 1] + e.val);
            }
        }
    }
}

int main() {
    n = read(); q = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    DP(1, 0);
    printf("%d\n", dp[1][q]);
    return 0;
}