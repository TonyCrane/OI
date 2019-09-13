/*************************************************************
 *  > File Name        : P1600.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/09 13:01:25
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

const int maxn = 300010;

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

int f[maxn][21], dep[maxn], n, m;

void bfs(int s) {
    queue<int> q;
    q.push(s); dep[s] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (dep[e.to]) continue;
            dep[e.to] = dep[x] + 1;
            f[e.to][0] = x;
            for (int j = 1; j <= 20; ++j) {
                f[e.to][j] = f[f[e.to][j - 1]][j - 1];
            }
            q.push(e.to);
        }
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (dep[f[y][i]] >= dep[x]) {
            y = f[y][i];
        }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

vector<int> a1[maxn], b1[maxn], a2[maxn], b2[maxn];
int c1[maxn << 1], c2[maxn << 1], ans[maxn], w[maxn];
bool vis[maxn];

void dfs(int x) {
    int v1 = c1[dep[x] + w[x]];
    int v2 = c2[w[x] - dep[x] + n];
    vis[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (vis[e.to]) continue;
        dfs(e.to);
    }
    for (int i = 0; i < a1[x].size(); ++i) c1[a1[x][i]]++;
    for (int i = 0; i < b1[x].size(); ++i) c1[b1[x][i]]--;
    for (int i = 0; i < a2[x].size(); ++i) c2[a2[x][i] + n]++;
    for (int i = 0; i < b2[x].size(); ++i) c2[b2[x][i] + n]--;
    ans[x] += c1[dep[x] + w[x]] - v1 + c2[w[x] - dep[x] + n] - v2;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        w[i] = read();
    }
    bfs(1);
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        int z = lca(x, y);
        a1[x].push_back(dep[x]);
        b1[f[z][0]].push_back(dep[x]);
        a2[y].push_back(dep[x] - 2 * dep[z]);
        b2[z].push_back(dep[x] - 2 * dep[z]);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}