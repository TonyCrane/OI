/*************************************************************
 *  > File Name        : P2146.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/24 17:19:48
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
int n, m, cnt;

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
    int l, r, len;
    int dat, laz; // 0 装了 1 没装
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) tree[p].len
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];

inline void pushup(int p) {
    dat(p) = dat(p<<1) + dat(p<<1|1);
}

inline void pushdown(int p) {
    if (laz(p) == -1) return;
    laz(p<<1) = laz(p<<1|1) = laz(p);
    dat(p<<1) = laz(p) * len(p<<1);
    dat(p<<1|1) = laz(p) * len(p<<1|1);
    laz(p) = -1;
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r; 
    laz(p) = -1; len(p) = r - l + 1;
    if (l == r) {
        dat(p) = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int opt) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) = opt * len(p);
        laz(p) = opt;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, opt);
    if (r >  mid) update(p<<1|1, l, r, opt);
    pushup(p);
}

int query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return dat(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1, ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

/*- QueryAndOperation -*/
int qSon(int x) {
    return siz[x] - query(1, id[x], id[x] + siz[x] - 1);
}

void updSon(int x) {
    update(1, id[x], id[x] + siz[x] - 1, 1); // 全标为未装
}

int qRange(int x, int y) {
    int ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(1, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += query(1, id[x], id[y]);
    return ans;
}

void updRange(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, id[top[x]], id[x], 0);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, id[x], id[y], 0);
}

int main() {
    n = read();
    for (int u = 2; u <= n; ++u) {
        int v = read() + 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    m = read();
    for (int i = 1; i <= m; ++i) {
        char opt[12]; scanf("%s", opt);
        if (opt[0] == 'i') {
            int x = read() + 1;
            printf("%d\n", qRange(x, 1));
            updRange(x, 1);
        } else {
            int x = read() + 1;
            printf("%d\n", qSon(x));
            updSon(x);
        }
    }
    return 0;
}