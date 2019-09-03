/*************************************************************
 *  > File Name        : P1967.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/02 15:53:51
 *  > Algorithm        : Kruskal+LCA
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;
const int inf  = 0x7fffffff;

int n, m, q;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;  vector<Edge> trees;
vector<int> G[maxn]; vector<int> T[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}
void addtree(int u, int v, int w) {
    trees.push_back(Edge(u, v, w));
    trees.push_back(Edge(v, u, w));
    int mm = trees.size();
    T[v].push_back(mm - 1);
    T[u].push_back(mm - 2);
}

bool cmp(Edge a, Edge b) {
    return a.val > b.val;
}
int ufs[maxn];
inline int find(int x) { 
    return ufs[x] == x ? x : ufs[x] = find(ufs[x]); 
}

void Kruskal() {
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < m; ++i) {
        Edge& e = edges[i];
        int x = find(e.from), y = find(e.to);
        if (x != y) {
            ufs[x] = y;
            addtree(e.from, e.to, e.val);
        }
    }
}

int vis[maxn], dep[maxn], f[maxn][21], w[maxn][21];

void dfs(int x) {
    vis[x] = true;
    for (int i = 0; i < T[x].size(); ++i) {
        Edge& e = trees[T[x][i]];
        if (vis[e.to]) continue;
        dep[e.to] = dep[x] + 1;
        f[e.to][0] = x;
        w[e.to][0] = e.val;
        dfs(e.to);
    }
}

int lca(int x, int y) {
    if (find(x) != find(y)) return -1;
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
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    Kruskal();
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
    q = read();
    for (int i = 1; i <= q; ++i) {
        int x = read(), y = read();
        printf("%d\n", lca(x, y));
    }
    return 0;
}