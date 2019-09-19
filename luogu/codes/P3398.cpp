/*************************************************************
 *  > File Name        : P3398.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 14:51:04
 *  > Algorithm        : LCA
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
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    edges.push_back(Edge(v, u));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

int f[maxn][20], d[maxn];
int n, m, t;
void bfs(int s) {
    queue<int> q;
    q.push(s); d[s] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (d[e.to]) continue;
            d[e.to] = d[x] + 1;
            f[e.to][0] = x;
            for (int j = 1; j <= t; ++j) {
                f[e.to][j] = f[f[e.to][j - 1]][j - 1];
            }
            q.push(e.to);
        }
    }
}
int lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = t; i >= 0; --i) {
        if (d[f[y][i]] >= d[x]) y = f[y][i];
    }
    if (x == y) return x;
    for (int i = t; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

int main() {
    n = read(), m = read();
    t = (int)(log(n) / log(2)) + 1;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    bfs(1);
    for (int i = 1; i <= m; ++i) {
        int _x1 = read(), _y1 = read(), _x2 = read(), _y2 = read();
        int p = lca(_x1, _y1);
        int q = lca(_x2, _y2);
        if (p == q) {
            puts("Y");
        } else if (d[p] < d[q]) {
            if (lca(q, _x1) == q || lca(q, _y1) == q) {
                puts("Y");
            } else {
                puts("N");
            }
        } else {
            if (lca(p, _x2) == p || lca(p, _y2) == p) {
                puts("Y");
            } else {
                puts("N");
            }
        }
    }
    return 0;
}