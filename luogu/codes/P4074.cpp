/*************************************************************
 *  > File Name        : P4074.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/05/06 09:50:46
 *  > Algorithm        : 树上带修莫队
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

int n, m, q_, l, r, t, len, ocnt, cntq, cntr;
int cnt[maxn], fst[maxn], lst[maxn], vis[maxn], blk[maxn];
int ord[maxn], val[maxn], dep[maxn], wgt[maxn], col[maxn], fa[maxn][25];
LL Ans, ans[maxn];

struct Query {
    int l, r, t, id, lca;
}q[maxn];
bool cmp(Query a, Query b) {
    if (blk[a.l] != blk[b.l]) return blk[a.l] < blk[b.l];
    if (blk[a.r] != blk[b.r]) return blk[a.r] < blk[b.r];
    return a.t < b.t;
}

struct Change {
    int pos, color;
}c[maxn];

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
    Ans += (LL)wgt[++cnt[x]] * val[x];
}
void del(int x) {
    Ans -= (LL)wgt[cnt[x]--] * val[x];
}
void upd(int x) {
    if (!vis[x]) add(col[x]);
    else del(col[x]);
    vis[x] ^= 1;
}
void chg(int t) {
    if (vis[c[t].pos]) {
        add(c[t].color); del(col[c[t].pos]);
    }
    swap(col[c[t].pos], c[t].color);
}

int main() {
    n = read(); m = read(); q_ = read();
    for (int i = 1; i <= m; ++i) val[i] = read();
    for (int i = 1; i <= n; ++i) wgt[i] = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) col[i] = read();
    dep[1] = 1; dfs(1, 0);
    for (int i = 1; i <= q_; ++i) {
        int opt = read();
        if (opt == 0) {
            int x = read(), y = read();
            c[++cntr].pos = x; c[cntr].color = y;
        } else {
            int x = read(), y = read(); int LCA = lca(x, y);
            if (fst[x] > fst[y]) swap(x, y); cntq++;
            if (x == LCA) q[cntq].l = fst[x], q[cntq].r = fst[y];
            else q[cntq].l = lst[x], q[cntq].r = fst[y], q[cntq].lca = LCA;
            q[cntq].id = cntq; q[cntq].t = cntr;
        }
    }
    len = pow(2 * n, cntr ? 2.0 / 3.0 : 1.0 / 2.0);
    for (int i = 1; i <= 2 * n; ++i) blk[i] = (i - 1) / len + 1;
    sort(q + 1, q + 1 + cntq, cmp); l = 1;
    for (int i = 1; i <= cntq; ++i) {
        while (l < q[i].l) upd(ord[l++]);
        while (r > q[i].r) upd(ord[r--]);
        while (l > q[i].l) upd(ord[--l]);
        while (r < q[i].r) upd(ord[++r]);
        while (t < q[i].t) chg(++t);
        while (t > q[i].t) chg(t--);
        if (q[i].lca) upd(q[i].lca);
        ans[q[i].id] = Ans;
        if (q[i].lca) upd(q[i].lca);
    }
    for (int i = 1; i <= cntq; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}