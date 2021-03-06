/*************************************************************
 *  > File Name        : P3292.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/13 15:06:35
 *  > Algorithm        : 倍增线性基(LCA)
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

const int maxn = 20010;

int n, q;
LL ans[maxn], f[maxn][21], p[maxn][21][62], d[maxn];

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

bool insert(LL* p, LL x) {
    for (int i = 61; i >= 0; --i) {
        if (x & (1LL << i)) {
            if (p[i]) x ^= p[i];
            else {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

void merge(LL* p1, LL* p2) {
    for (int i = 61; i >= 0; --i) {
        if (p2[i]) {
            insert(p1, p2[i]);
        }
    }
}

void dfs(int u, int fa) {
    f[u][0] = fa;
    d[u] = d[fa] + 1;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == fa) continue;
        dfs(e.to, u);
    }
}

void lca(int x, int y) {
    if (d[x] > d[y]) swap(x, y);
    for (int i = 20; i >= 0; --i) {
        if (d[f[y][i]] >= d[x]) {
            merge(ans, p[y][i]);
            y = f[y][i];
        }
    }
    if (x == y) {
        merge(ans, p[x][0]);
        return;
    }
    for (int i = 20; i >= 0; --i) {
        if (f[x][i] != f[y][i]) {
            merge(ans, p[x][i]);
            merge(ans, p[y][i]);
            x = f[x][i];
            y = f[y][i];
        }
    }
    merge(ans, p[x][0]);
    merge(ans, p[y][0]);
    merge(ans, p[f[y][0]][0]);
}

int main() {
    n = read(); q = read();
    for (int i = 1; i <= n; ++i) {
        LL a = read();
        insert(p[i][0], a);
    }
    for (int i = 1; i <= n - 1; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs(1, 0);
    for (int j = 1; j <= 20; ++j) {
        for (int i = 1; i <= n; ++i) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            memcpy(p[i][j], p[i][j - 1], sizeof(p[i][j - 1]));
            merge(p[i][j], p[f[i][j - 1]][j - 1]);
        }
    }
    for (int i = 1; i <= q; ++i) {
        memset(ans, 0, sizeof(ans));
        int u = read(), v = read();
        lca(u, v);
        LL res = 0;
        for (int j = 61; j >= 0; --j) {
            if ((res ^ ans[j]) > res) res ^= ans[j];
        }
        printf("%lld\n", res);
    }
    return 0;
}