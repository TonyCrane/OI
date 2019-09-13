/*************************************************************
 *  > File Name        : P3387.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/13 22:45:15
 *  > Algorithm        : SCC+DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;  vector<Edge> nedges;
vector<int> G[maxn]; vector<int> nG[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}
void nadd(int u, int v) {
    nedges.push_back(Edge(u, v));
    int mm = nedges.size();
    nG[u].push_back(mm - 1);
}

int dfn[maxn], low[maxn], c[maxn];
int n, m, num, cnt, val[maxn], sum[maxn];
stack<int> s; bool ins[maxn];
vector<int> scc[maxn];

void tarjan(int x) {
    dfn[x] = low[x] = ++num; s.push(x); ins[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            tarjan(e.to);
            low[x] = min(low[x], low[e.to]);
        } else if (ins[e.to]) {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
    if (dfn[x] == low[x]) {
        cnt++; int y;
        do {
            y = s.top(); s.pop(); ins[y] = false;
            c[y] = cnt; scc[cnt].push_back(y);
            sum[cnt] += val[y];
        } while (x != y);
    }
}

int dp[maxn], ans;

void DP(int x) {
    if (dp[x]) return;
    dp[x] = sum[x];
    int maxs = 0;
    for (int i = 0; i < nG[x].size(); ++i) {
        Edge& e = nedges[nG[x][i]];
        if (!dp[e.to]) DP(e.to);
        maxs = max(maxs, dp[e.to]);
    }
    dp[x] += maxs;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        val[i] = read();
    }
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (c[u] == c[e.to]) continue;
            nadd(c[u], c[e.to]);
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        if (!dp[i]) {
            DP(i);
            ans = max(ans, dp[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}