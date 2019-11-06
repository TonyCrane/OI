/*************************************************************
 *  > File Name        : c1084_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/05 16:53:17
 *  > Algorithm        : 
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

const LL maxn = 50010;
const LL mod  = 2019;

vector<LL> G[maxn];

LL n, q, cnt, w[maxn], wt[maxn], old[maxn];
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
    wt[id[u]] = w[u]; old[id[u]] = u;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (LL i = 0; i < G[u].size(); ++i) {
        LL& v = G[u][i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

struct Node {
    LL l, r;
    LL dat1, dat2, laz, k1, k2;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define dat1(p) tree[p].dat1
    #define dat2(p) tree[p].dat2
    #define laz(p) tree[p].laz
    #define k1(p) tree[p].k1
    #define k2(p) tree[p].k2
}tree[maxn << 2];

inline void pushup(LL p) {
    dat1(p) = dat1(p<<1) + dat1(p<<1|1);
    dat2(p) = dat2(p<<1) + dat2(p<<1|1);
    k1(p) = k1(p<<1) + k1(p<<1|1);
    k2(p) = k2(p<<1) + k2(p<<1|1);
}

inline void pushdown(LL p) {
    if (laz(p)) {
        laz(p<<1) += laz(p);
        laz(p<<1|1) += laz(p);
        dat1(p<<1) += laz(p) * dat2(p<<1); dat1(p<<1) %= mod;
        dat1(p<<1|1) += laz(p) * dat2(p<<1|1); dat2(p<<1|1) %= mod;
        k1(p<<1) += k2(p<<1) * laz(p); k1(p<<1) %= mod;
        k1(p<<1|1) += k2(p<<1|1) * laz(p); k1(p<<1|1) %= mod;
        laz(p) = 0;
    }
}

void build(LL p, LL l, LL r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        dat2(p) = siz[old[l]] * (n - siz[old[l]]);
        dat1(p) = dat2(p) * wt[l];
        k1(p) = siz[old[l]] * wt[l];
        k2(p) = siz[old[l]];
        return;
    }
    LL mid = (l(p) + r(p)) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void update(LL p, LL l, LL r, LL k) {
    if (l <= l(p) && r(p) <= r) {
        dat1(p) += dat2(p) * k; dat1(p) %= mod;
        k1(p) += k2(p) * k; k1(p) %= mod;
        laz(p) += k; laz(p) %= mod;
        return;
    }
    pushdown(p);
    LL mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}

pair<LL, LL> query(LL p, LL l, LL r) {
    if (l <= l(p) && r(p) <= r) return pair<LL, LL>(dat1(p) % mod, k1(p) % mod);
    pushdown(p);
    LL mid = (l(p) + r(p)) >> 1, ans1 = 0, ans2 = 0;
    if (l <= mid) {
        pair<LL, LL> ans = query(p<<1, l, r);
        ans1 += ans.first;  ans1 %= mod;
        ans2 += ans.second; ans2 %= mod;
    }
    if (r >  mid) {
        pair<LL, LL> ans = query(p<<1|1, l, r);
        ans1 += ans.first;  ans1 %= mod;
        ans2 += ans.second; ans2 %= mod;
    }
    return pair<LL, LL>(ans1, ans2);
}

void updRange(LL x, LL y, LL k) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        if (top[x] != 1) update(1, id[top[x]], id[x], k);
        else update(1, id[2], id[x], k);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    update(1, id[y] + 1, id[x], k);
}

LL qSon(LL x) {
    pair<LL, LL> res = query(1, id[x] + 1, id[x] + siz[x] - 1);
    return (res.first - (n - siz[x]) * res.second + mod * 10000000) % mod;
}

int main() {
    n = read(); q = read();
    for (LL i = 2; i <= n; ++i) {
        LL p = read(), c = read();
        G[p].push_back(i);
        G[i].push_back(p);
        w[i] += c;
    }
    dfs1(1, 1, 1);
    dfs2(1, 1);
    build(1, 1, n);
    for (LL i = 1; i <= q; ++i) {
        char opt[5]; scanf("%s", opt);
        if (opt[0] == 'I') {
            LL u = read(), v = read(), w = read();
            updRange(u, v, w);
        } else {
            LL p = read();
            printf("%lld\n", qSon(p));
        }
    }
    return 0;
}