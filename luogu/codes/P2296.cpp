/*************************************************************
 *  > File Name        : P2296.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 19:40:45
 *  > Algorithm        : Dijkstra 反图删边
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w = 1): from(u), to(v), val(w) {}
};
vector<Edge> edges; vector<int> G[maxn];
vector<Edge> antie; vector<int> antiG[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    antie.push_back(Edge(v, u));
    int mm = edges.size();
    G[u].push_back(mm - 1);
    antiG[v].push_back(mm - 1);
}

int n, m, s, t, dis[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < antiG[u].size(); ++i) {
        Edge& e = antie[antiG[u][i]];
        if (!vis[e.to]) {
            dfs(e.to);
        }
    }
}

struct heap {
    int u, d;
    heap(int u, int d): u(u), d(d) {}
    bool operator < (const heap& a) const {
        return d > a.d;
    }
};
void Dijkstra(int s) {
    priority_queue<heap> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0; q.push(heap(s, 0));
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != dis[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                q.push(heap(e.to, dis[e.to]));
            }
        }
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    s = read(); t = read();
    dfs(t);
    for (int u = 1; u <= n; ++u) {
        if (!vis[u]) {
            for (int i = 0; i < antiG[u].size(); ++i) {
                Edge& e = antie[antiG[u][i]];
                if (vis[e.to]) {
                    G[e.to].clear();
                }
            }
        }
    }
    Dijkstra(s);
    printf("%d\n", dis[t] == 0x3f3f3f3f ? -1 : dis[t]);
    return 0;
}