/*************************************************************
 *  > File Name        : P4719.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/06 15:21:04
 *  > Algorithm        : 动态DP
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
const int inf  = 0x3f3f3f3f;

int n, m;

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

/*------- Matrix -------*/
struct Matrix {
    int mat[2][2];
    void init() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                mat[i][j] = -inf;
            }
        }
    }
    Matrix operator * (const Matrix& a) const {
        Matrix ans; ans.init();
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    ans.mat[i][j] = max(ans.mat[i][j], mat[i][k] + a.mat[k][j]);
                }
            }
        }
        return ans;
    }
};

/*------- TreeChainSplit -------*/
int cnt, ed[maxn], old[maxn];
int son[maxn], id[maxn], fa[maxn], dep[maxn], siz[maxn], top[maxn];

void dfs1(int x, int f, int depth) {
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

void dfs2(int x, int topf) {
    id[x] = ++cnt;
    old[id[x]] = x;
    top[x] = topf;
    ed[topf] = id[x];
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa[x] || e.to == son[x]) continue;
        dfs2(e.to, e.to);
    }
}

/*------- TreeDP -------*/
int dp[maxn][2], ldp[maxn][2], wt[maxn];

void DP(int u) {
    ldp[u][1] = wt[u];
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == fa[u] || e.to == son[u]) continue;
        DP(e.to);
        ldp[u][0] += max(dp[e.to][1], dp[e.to][0]);
        ldp[u][1] += dp[e.to][0];
    }
    dp[u][0] += ldp[u][0];
    dp[u][1] += ldp[u][1];
    if (!son[u]) return;
    DP(son[u]);
    dp[u][0] += max(dp[son[u]][0], dp[son[u]][1]);
    dp[u][1] += dp[son[u]][0];
}

/*------- SegmentTree -------*/
struct Node {
    int l, r;
    Matrix dat;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define dat(p) tree[p].dat
    #define val(p) tree[p].val
}tree[maxn << 2];
Matrix val[maxn];

void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        val[old[l]].mat[0][0] = ldp[old[l]][0]; 
        val[old[l]].mat[0][1] = ldp[old[l]][0];
        val[old[l]].mat[1][0] = ldp[old[l]][1];
        val[old[l]].mat[1][1] = -inf;
        dat(p) = val[old[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    dat(p) = dat(p<<1) * dat(p<<1|1);
}

void update(int p, int id) {
    if (l(p) == r(p) && l(p) == id) {
        dat(p) = val[old[id]];
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    if (id <= mid) update(p<<1, id);
    if (id >  mid) update(p<<1|1, id);
    dat(p) = dat(p<<1) * dat(p<<1|1); 
}

Matrix query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return dat(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l >  mid) return query(p<<1|1, l, r);
    if (r <= mid) return query(p<<1, l, r);
    return query(p<<1, l, r) * query(p<<1|1, l, r);
}

void change(int u, int w) {
    val[u].mat[1][0] += w - wt[u];
    wt[u] = w;
    while (u != 0) {
        int now = top[u];
        Matrix la = query(1, id[now], ed[now]);
        update(1, id[u]);
        Matrix nw = query(1, id[now], ed[now]);
        u = fa[now];
        val[u].mat[0][0] += max(nw.mat[0][0], nw.mat[1][0]) - max(la.mat[0][0], la.mat[1][0]);
        val[u].mat[0][1] = val[u].mat[0][0];
        val[u].mat[1][0] += nw.mat[0][0] - la.mat[0][0];
    }
}

/*------- Main -------*/
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        wt[i] = read();
    }
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);
    DP(1);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int u = read(), w = read();
        change(u, w);
        Matrix ans = query(1, id[1], ed[1]);
        printf("%d\n", max(ans.mat[0][0], ans.mat[1][0]));
    }
    return 0;
}