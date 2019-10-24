/*************************************************************
 *  > File Name        : P2486.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/23 21:12:40
 *  > Algorithm        : TreeChainSplit
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

vector<int> G[maxn];
int n, m, cnt, w[maxn], wt[maxn];

/*- TreeChainSplit -*/
int dep[maxn], fa[maxn], siz[maxn], son[maxn], id[maxn], top[maxn];

void dfs1(int u, int f, int depth) {
    dep[u] = depth; fa[u] = f;
    siz[u] = 1; int maxs = -1;
    for (int i = 0; i < G[u].size(); ++i) {
        int& v = G[u][i];
        if (v == f) continue;
        dfs1(v, u, depth + 1);
        siz[u] += siz[v];
        if (siz[v] > maxs) {
            son[u] = v;
            maxs = siz[v];
        }
    }
}

void dfs2(int u, int topf) {
    id[u] = ++cnt; top[u] = topf;
    wt[id[u]] = w[u];
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (int i = 0; i < G[u].size(); ++i) {
        int& v = G[u][i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

/*- SegmentTree -*/
struct Node {
    int l, r;
    int lco, rco, dat, laz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define lco(p) tree[p].lco
    #define rco(p) tree[p].rco
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];

inline void pushup(int p) {
    dat(p) = dat(p<<1) + dat(p<<1|1);
    if (rco(p<<1) == lco(p<<1|1)) dat(p)--;
    lco(p) = lco(p<<1); rco(p) = rco(p<<1|1);
}

inline void pushdown(int p) {
    if (laz(p)) {
        dat(p<<1) = dat(p<<1|1) = 1;
        laz(p<<1) = laz(p<<1|1) = laz(p);
        lco(p<<1) = lco(p<<1|1) = laz(p);
        rco(p<<1) = rco(p<<1|1) = laz(p);
        laz(p) = 0;
    }
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        lco(p) = rco(p) = wt[l];
        dat(p) = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int col) {
    if (l <= l(p) && r(p) <= r) {
        lco(p) = rco(p) = laz(p) = col;
        dat(p) = 1;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, col);
    if (r >  mid) update(p<<1|1, l, r, col);
    pushup(p);
}

int query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) {
        return dat(p);
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1, ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    if (l <= mid && mid < r && rco(p<<1) == lco(p<<1|1)) ans--;
    return ans; 
}

/*- Query And Operation -*/
inline void updRange(int x, int y, int col) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, id[top[x]], id[x], col);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, id[x], id[y], col);
}

int qPoint(int p, int pos) {
    if (l(p) == pos && r(p) == pos) return lco(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (pos <= mid) return qPoint(p<<1, pos);
    else return qPoint(p<<1|1, pos);
}

inline int qRange(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(1, id[top[x]], id[x]);
        int cols = qPoint(1, id[top[x]]);
        int colf = qPoint(1, id[fa[top[x]]]);
        if (cols == colf) ans--;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += query(1, id[x], id[y]);
    return ans;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) w[i] = read();
    for (int i = 1; i <  n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        char opt = getchar();
        while (opt != 'C' && opt != 'Q') opt = getchar();
        if (opt == 'C') {
            int a = read(), b = read(), c = read();
            updRange(a, b, c);
        } else {
            int a = read(), b = read();
            printf("%d\n", qRange(a, b));
        }
    }
    return 0;
}