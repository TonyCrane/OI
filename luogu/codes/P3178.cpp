/*************************************************************
 *  > File Name        : P3178.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/27 12:41:03
 *  > Algorithm        : TreeChainSplit
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 100010;

vector<LL> G[maxn];
LL n, m, cnt, w[maxn], wt[maxn];

/*- TreeChainSplit -*/
LL dep[maxn], fa[maxn], siz[maxn], son[maxn], id[maxn], top[maxn];

void dfs1(LL u, LL f, LL depth) {
    dep[u] = depth; fa[u] = f;
    siz[u] = 1; LL maxs = -1;
    for (LL i = 0; i < G[u].size(); ++i) {
        LL& v = G[u][i];
        if (v == f) continue;
        dfs1(v, u, depth + 1);
        siz[u] += siz[v];
        if (siz[v] > maxs) {
            son[u] = v;
            maxs = siz[v];
        }
    }
}

void dfs2(LL u, LL topf) {
    id[u] = ++cnt; top[u] = topf;
    wt[id[u]] = w[u];
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (LL i = 0; i < G[u].size(); ++i) {
        LL& v = G[u][i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

/*- SegmentTree -*/
struct Node {
    LL l, r, len;
    LL dat, laz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) tree[p].len
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];

inline void pushup(LL p) {
    dat(p) = dat(p<<1) + dat(p<<1|1);
}

inline void pushdown(LL p) {
    if (laz(p)) {
        laz(p<<1) += laz(p);
        laz(p<<1|1) += laz(p);
        dat(p<<1) += laz(p) * len(p<<1);
        dat(p<<1|1) += laz(p) * len(p<<1|1);
        laz(p) = 0;
    }
}

void build(LL p, LL l, LL r) {
    l(p) = l; r(p) = r; len(p) = r - l + 1;
    if (l == r) {
        dat(p) = wt[l];
        return;
    }
    LL mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void update(LL p, LL l, LL r, LL k) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) += k * len(p);
        laz(p) += k;
        return;
    }
    pushdown(p);
    LL mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}

LL query(LL p, LL l, LL r) {
    if (l <= l(p) && r(p) <= r) return dat(p);
    pushdown(p);
    LL mid = (l(p) + r(p)) >> 1, ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

/*- QueryAndOperation -*/
LL qRange(LL x, LL y) {
    LL ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(1, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += query(1, id[x], id[y]);
    return ans;
}

void updRange(LL x, LL y, LL k) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, id[x], id[y], k);
}

void updSon(LL x, LL k) {
    update(1, id[x], id[x] + siz[x] - 1, k);
}

int main() {
    n = read(); m = read();
    for (LL i = 1; i <= n; ++i) w[i] = read();
    for (LL i = 1; i <  n; ++i) {
        LL x = read(), y = read();
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for (LL i = 1; i <= m; ++i) {
        LL opt = read();
        if (opt == 1) {
            LL x = read(), y = read();
            updRange(x, x, y);
        } else if (opt == 2) {
            LL x = read(), y = read();
            updSon(x, y);
        } else {
            LL x = read();
            printf("%lld\n", qRange(x, 1));
        }
    }
    return 0;
}