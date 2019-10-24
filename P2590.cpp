/*************************************************************
 *  > File Name        : P2590.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/24 21:35:31
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

const int maxn = 30010;

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
    int l, r, len;
    int maxx, sum;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) tree[p].len
    #define sum(p) tree[p].sum
    #define maxx(p) tree[p].maxx
}tree[maxn << 2];

inline void pushup(int p) {
    sum(p) = sum(p<<1) + sum(p<<1|1);
    maxx(p) = max(maxx(p<<1), maxx(p<<1|1));
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r; len(p) = r - l + 1;
    if (l == r) {
        sum(p) = maxx(p) = wt[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int k) {
    if (l <= l(p) && r(p) <= r) {
        sum(p) = k * len(p);
        maxx(p) = k;
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}

int querySum(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return sum(p);
    int mid = (l(p) + r(p)) >> 1, ans = 0;
    if (l <= mid) ans += querySum(p<<1, l, r);
    if (r >  mid) ans += querySum(p<<1|1, l, r);
    return ans;
}

int queryMax(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return maxx(p);
    int mid = (l(p) + r(p)) >> 1, ans = -0x3f3f3f3f;
    if (l <= mid) ans = max(ans, queryMax(p<<1, l, r));
    if (r >  mid) ans = max(ans, queryMax(p<<1|1, l, r));
    return ans;
}

/*- QueryAndOperation -*/
void updRange(int x, int y, int k) {

}

int qRange(int x, int y) {

}

int qMax(int x, int y) {

}

int main() {
    n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) w[i] = read();
    dfs1(1, 0, 1);
    dfs2(1, 1);
    build(1, 1, n);
    int q = read();
    for (int i = 1; i <= q; ++i) {
        char opt[20]; scanf("%s", opt);



        
    }
}