/*************************************************************
 *  > File Name        : P3379_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 14:56:58
 *  > Algorithm        : LCA-TreeChainSplit
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

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
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

int n, m, s;
int dep[maxn], siz[maxn], fa[maxn], son[maxn], top[maxn];

void dfs1(int x, int f, int depth) {
    dep[x] = depth; fa[x] = f;
    siz[x] = 1; int maxs = -1;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == f) continue;
        dfs1(e.to, x, depth + 1);
        siz[x] += siz[e.to];
        if (siz[e.to] > maxs) {
            son[x] = e.to;
            maxs = siz[e.to];
        }
    }
}

void dfs2(int x, int topf) {
    top[x] = topf;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa[x] || e.to == son[x]) continue;
        dfs2(e.to, e.to);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return x;
}

int main() {
    n = read(), m = read(), s = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs1(s, 0, 1);
    dfs2(s, s);
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        printf("%d\n", lca(x, y));
    }
    return 0;
}