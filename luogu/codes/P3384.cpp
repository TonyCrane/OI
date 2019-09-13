/*************************************************************
 *  > File Name        : P3384.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/13 21:01:40
 *  > Algorithm        : TreeChainSplit+SegmentTree
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

int n, m, r, mod, cnt, res, w[maxn], wt[maxn];
int son[maxn], id[maxn], fa[maxn], dep[maxn], siz[maxn], top[maxn];


/* SegmentTree */
struct SegmentTreeNode {
    int l, r, len;
    int dat, laz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) tree[p].len
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];

inline void pushup(int p) {
    dat(p) = (dat(p<<1) + dat(p<<1|1)) % mod;
}

inline void pushdown(int p) {
    laz(p<<1) += laz(p);
    laz(p<<1|1) += laz(p);
    dat(p<<1) += laz(p) * (len(p) - (len(p) >> 1));
    dat(p<<1|1) += laz(p) * (len(p) >> 1);
    dat(p<<1) %= mod;
    dat(p<<1|1) %= mod;
    laz(p) = 0;
}

inline void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    len(p) = r - l + 1;
    if (l == r) {
        dat(p) = wt[l] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

inline void query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) {
        res += dat(p);
        res %= mod;
        return;
    }
    if (laz(p)) pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) query(p<<1, l, r);
    if (r >  mid) query(p<<1|1, l, r);
}

inline void update(int p, int l, int r, int k) {
    if (l <= l(p) && r(p) <= r) {
        laz(p) += k;
        dat(p) += k * len(p);
        return;
    }
    if (laz(p)) pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}


/* Tree Chain Split */
inline void dfs1(int x, int f, int depth) {
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

inline void dfs2(int x, int topf) {
    id[x] = ++cnt;
    wt[id[x]] = w[x];
    top[x] = topf;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa[x] || e.to == son[x]) continue;
        dfs2(e.to, e.to);
    }
}


/* Query And Operation */
inline void updRange(int x, int y, int k) {
    k %= mod;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, id[x], id[y], k);
}

inline int qRange(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res = 0;
        query(1, id[top[x]], id[x]);
        ans += res; ans %= mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    res = 0;
    query(1, id[x], id[y]);
    ans += res; ans %= mod;
    return ans;
}

inline void updSubtree(int x, int k) {
    update(1, id[x], id[x] + siz[x] - 1, k);
}

inline int qSubtree(int x) {
    res = 0;
    query(1, id[x], id[x] + siz[x] - 1);
    return res;
}

int main() {
    n = read(); m = read(); r = read(); mod = read();
    for (int i = 1; i <= n; ++i) {
        w[i] = read();
    }
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int opt = read(), x, y, z;
        switch (opt) {
            case 1:
                x = read(); y = read(); z = read();
                updRange(x, y, z);
                break;
            case 2:
                x = read(); y = read();
                printf("%d\n", qRange(x, y));
                break;
            case 3:
                x = read(); z = read();
                updSubtree(x, z);
                break;
            case 4:
                x = read();
                printf("%d\n", qSubtree(x));
                break;
        }
    }
    return 0;
}