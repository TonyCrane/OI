/*************************************************************
 *  > File Name        : P3379_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/01 15:32:24
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
    n = read(), m = read(); int s = read();
    t = (int)(log(n) / log(2)) + 1;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    bfs(s);
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        printf("%d\n", lca(x, y));
    }
    return 0;
}