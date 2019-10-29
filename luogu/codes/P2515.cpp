/*************************************************************
 *  > File Name        : P2515.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/29 12:55:26
 *  > Algorithm        : Tarjan + 树形DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 510;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}
void clear() {
    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
}

int n, m, w[maxn], v[maxn], d[maxn], deg[maxn];
int dp[maxn][maxn], _w[maxn], _v[maxn];
int low[maxn], dfn[maxn], dfnc, color[maxn];
stack<int> s; bool ins[maxn];
vector<int> scc[maxn]; int cnt;

void Tarjan(int x) {
    low[x] = dfn[x] = ++dfnc;
    s.push(x); ins[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            Tarjan(e.to);
            low[x] = min(low[x], low[e.to]);
        } else if (ins[e.to]) {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
    if (low[x] == dfn[x]) {
        cnt++; int y;
        do {
            y = s.top(); s.pop(); ins[y] = false;
            color[y] = cnt; scc[cnt].push_back(y);
            _w[cnt] += w[y]; _v[cnt] += v[y];
        } while (x != y);
    }
}

void DP(int u) {
    for (int i = _w[u]; i <= m; ++i) dp[u][i] = _v[u];
    for (int a = 0; a < G[u].size(); ++a) {
        Edge& e = edges[G[u][a]];
        DP(e.to);
        for (int i = m - _w[u]; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[u][i + _w[u]] = max(dp[u][i + _w[u]], dp[e.to][j] + dp[u][i + _w[u] - j]);
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) w[i] = read();
    for (int i = 1; i <= n; ++i) v[i] = read();
    for (int i = 1; i <= n; ++i) {
        d[i] = read();
        if (d[i]) {
            add(d[i], i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) Tarjan(i);
    }
    clear();
    for (int i = 1; i <= n; ++i) {
        if (color[d[i]] != color[i]) {
            add(color[d[i]], color[i]);
            deg[color[i]]++;
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        if (!deg[i]) add(0, i);
    }
    DP(0);
    printf("%d\n", dp[0][m]);
    return 0;
}