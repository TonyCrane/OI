/*************************************************************
 *  > File Name        : SP10707.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/30 13:52:29
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200020;

int n, m, l, r, Ans, len, ocnt;
int cnt[maxn], fst[maxn], lst[maxn], vis[maxn], ans[maxn];
int ord[maxn], val[maxn], dep[maxn], fa[maxn][25], old[maxn];

struct Query {
    int l, r, id, pos, lca;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}

struct Edge {
    int from, to;
    Edge(int f, int t): from(f), to(t) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int f, int t) {
    edges.push_back(Edge(f, t));
    edges.push_back(Edge(t, f));
    int mm = edges.size();
    G[t].push_back(mm - 1);
    G[f].push_back(mm - 2);
}

void dfs(int u, int f) {
    ord[++ocnt] = u; fst[u] = ocnt;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == f) continue;
        dep[e.to] = dep[u] + 1;
        fa[e.to][0] = u;
        for (int j = 1; j <= 20; ++j) {
            fa[e.to][j] = fa[fa[e.to][j - 1]][j - 1];
        }
        dfs(e.to, u);
    }
    ord[++ocnt] = u; lst[u] = ocnt;
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (dep[fa[y][i]] >= dep[x]) y = fa[y][i];
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; --i) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void add(int x) {
    cnt[val[x]]--;
    if (!cnt[val[x]]) Ans--;
}
void del(int x) {
    cnt[val[x]]++;
    if (cnt[val[x]] == 1) Ans++;
}
void chg(int x) {
    if (vis[x]) add(x);
    else del(x);
    vis[x] ^= 1;
}

int main() {
    n = read(); m = read(); len = sqrt(2 * n);
    for (int i = 1; i <= n; ++i) old[i] = val[i] = read();
    sort(old + 1, old + 1 + n); int len_ = unique(old + 1, old + 1 + n) - old - 1;
    for (int i = 1; i <= n; ++i) val[i] = lower_bound(old + 1, old + 1 + len_, val[i]) - old;
    for (int i = 1; i < n; ++i) add(read(), read()); 
    dep[1] = 1; dfs(1, 0);
    for (int i = 1; i <= m; ++i) {
        int il = read(), ir = read();
        int LCA = lca(il, ir);
        if (fst[il] > fst[ir]) swap(il, ir);
        if (il == LCA) {
            q[i].l = fst[il]; q[i].r = fst[ir];
        } else {
            q[i].l = lst[il]; q[i].r = fst[ir]; q[i].lca = LCA;
        }
        q[i].id = i; q[i].pos = (q[i].l - 1) / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) chg(ord[l++]);
        while (r > q[i].r) chg(ord[r--]);
        while (l > q[i].l) chg(ord[--l]);
        while (r < q[i].r) chg(ord[++r]);
        if (q[i].lca) chg(q[i].lca);
        ans[q[i].id] = Ans;
        if (q[i].lca) chg(q[i].lca);
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}