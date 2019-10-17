/*************************************************************
 *  > File Name        : P4568.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/17 16:17:46
 *  > Algorithm        : 分层图最短路
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
const int maxl = 15;

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

int n, m, k, dis[maxn][maxl];
bool vis[maxn][maxl];

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
    dis[s][0] = 0; q.push(heap(s, 0));
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int level = top.u / n, u = top.u % n;
        if (vis[u][level]) continue;
        vis[u][level] = true;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to][level] > dis[u][level] + e.val) {
                dis[e.to][level] = dis[u][level] + e.val;
                q.push(heap(e.to + level * n, dis[e.to][level]));
            }
            if (level < k && dis[e.to][level + 1] > dis[u][level]) {
                dis[e.to][level + 1] = dis[u][level];
                q.push(heap(e.to + (level + 1) * n, dis[e.to][level + 1]));
            }
        }
    }
}

int main() {
    n = read(); m = read(); k = read();
    int s = read(), t = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    Dijkstra(s);
    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans, dis[t][i]);
    }
    printf("%d\n", ans);
    return 0;
}