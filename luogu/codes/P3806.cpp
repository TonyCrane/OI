/*************************************************************
 *  > File Name        : P3806.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/13 22:16:40
 *  > Algorithm        : 点分治
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
const int maxk = 10000010;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

int n, m, sum, root, ans;
int maxp[maxn], size[maxn], dis[maxn], rem[maxn];
int q[maxn], query[maxn];
bool vis[maxn], test[maxk], judge[maxk];

void GetRoot(int u, int fa) {
    size[u] = 1; maxp[u] = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == fa || vis[e.to]) continue;
        GetRoot(e.to, u);
        size[u] += size[e.to];
        maxp[u] = max(maxp[u], size[e.to]);
    }
    maxp[u] = max(maxp[u], sum - size[u]);
    if (maxp[u] < maxp[root]) root = u;
}

void GetDist(int u, int fa) {
    rem[++rem[0]] = dis[u];
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == fa || vis[e.to]) continue;
        dis[e.to] = dis[u] + e.val;
        GetDist(e.to, u);
    }
}

void calc(int u) {
    int p = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (vis[e.to]) continue;
        rem[0] = 0; dis[e.to] = e.val;
        GetDist(e.to, u);
        for (int j = rem[0]; j; --j) {
            for (int k = 1; k <= m; ++k) {
                if (query[k] >= rem[j]) {
                    test[k] |= judge[query[k] - rem[j]];
                }
            }
        }
        for (int j = rem[0]; j; --j) {
            q[++p] = rem[j];
            judge[rem[j]] = true;
        }
    }
    for (int i = 1; i <= p; ++i) {
        judge[q[i]] = false;
    }
}

void solve(int u) {
    vis[u] = judge[0] = true;
    calc(u);
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (vis[e.to]) continue;
        sum = size[e.to]; maxp[root = 0] = maxk;
        GetRoot(e.to, 0); solve(root);
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    for (int i = 1; i <= m; ++i) {
        query[i] = read();
    }
    maxp[root] = sum = n;
    GetRoot(1, 0);
    solve(root);
    for (int i = 1; i <= m; ++i) {
        if (test[i]) printf("AYE\n");
        else printf("NAY\n");
    }
    return 0;
}