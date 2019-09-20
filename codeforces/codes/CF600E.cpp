/*************************************************************
 *  > File Name        : CF600E.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/20 16:06:18
 *  > Algorithm        : dsu on tree
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
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int n, Mx, Son, col[maxn], son[maxn], siz[maxn], cnt[maxn];
long long sum = 0, ans[maxn];

void dfs1(int x, int fa) {
    siz[x] = 1;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa) continue;
        dfs1(e.to, x);
        siz[x] += siz[e.to];
        if (siz[e.to] > siz[son[x]]) {
            son[x] = e.to;
        }
    }
}

void Add(int x, int fa, int val) {
    cnt[col[x]] += val;
    if (cnt[col[x]] > Mx) {
        Mx = cnt[col[x]];
        sum = col[x];
    } else if (cnt[col[x]] == Mx) {
        sum += (long long)col[x];
    }
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa || e.to == Son) continue;
        Add(e.to, x, val);
    }
}

void dfs2(int x, int fa, int opt) {
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa) continue;
        if (e.to != son[x]) dfs2(e.to, x, 0);
    }
    if (son[x]) {
        dfs2(son[x], x, 1);
        Son = son[x];
    }
    Add(x, fa, 1); Son = 0;
    ans[x] = sum;
    if (!opt) {
        Add(x, fa, -1);
        sum = 0, Mx = 0;
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        col[i] = read();
    }
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v); add(v, u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    return 0;
}