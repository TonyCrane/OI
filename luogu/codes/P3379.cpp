/*************************************************************
 *  > File Name        : P3379.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/06 15:35:26
 *  > Algorithm        : [Graph]LCA
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    edges.push_back(Edge(v, u));
    int mm = edges.size();
    G[u].push_back(mm - 2);
    G[v].push_back(mm - 1);
}

int n, m, s;
int dep[maxn], f[maxn][20], lg[maxn];

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; (1 << i) <= dep[u]; ++i) {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to != fa) {
            dfs(e.to, u);
        }
    }
}

int LCA(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    while (dep[x] > dep[y]) {
        x = f[x][lg[dep[x] - dep[y]] - 1];
    }
    if (x == y) return x;
    for (int k = lg[dep[x]] - 1; k >= 0; k--) {
        if (f[x][k] != f[y][k]) {
            x = f[x][k];
            y = f[y][k];
        }
    }
    return f[x][0];
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        add(x, y);
    }
    dfs(s, 0);
    for (int i = 1; i <= n; ++i) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
    return 0;
}