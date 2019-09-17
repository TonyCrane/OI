/*************************************************************
 *  > File Name        : c1066_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/17 12:50:00
 *  > Algorithm        : [Graph]LCA
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
const int inf  = 0x3f3f3f3f;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
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

int n, m;
bool vis[maxn];
int dep[maxn], f[maxn][21], w[maxn][21];

void dfs(int x) {
    vis[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (vis[e.to]) continue;
        dep[e.to] = dep[x] + 1;
        f[e.to][0] = x;
        w[e.to][0] = e.val;
        dfs(e.to);
    }
}

int lca(int x, int y) {
    int ans = inf;
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (dep[f[y][i]] >= dep[x]) {
            ans = min(ans, w[y][i]);
            y = f[y][i];
        }
    }
    if (x == y) return ans;
    for (int i = 20; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            ans = min(ans, min(w[x][i], w[y][i]));
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = min(ans, min(w[x][0], w[y][0]));
    return ans;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dep[i] = 1;
            dfs(i);
            f[i][0] = i;
            w[i][0] = inf;
        }
    }
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[j][i] = f[f[j][i - 1]][i - 1];
            w[j][i] = min(w[j][i - 1], w[f[j][i - 1]][i - 1]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        printf("%d\n", lca(x, y));
    }
    return 0;
}