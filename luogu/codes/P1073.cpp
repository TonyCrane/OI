/*************************************************************
 *  > File Name        : P1073.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/17 21:25:34
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

const int maxn = 100010;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn * 3];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int n, m, w[maxn];
int dis[maxn * 3];

struct heap {
    int u, d;
    bool operator < (const heap& a) const {
        return d > a.d;
    }
};

void Dijkstra(int s) {
    priority_queue<heap> q;
    memset(dis, -0x3f, sizeof(dis));
    dis[s] = 0;
    q.push((heap){s, 0});
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != dis[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] < dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                q.push((heap){e.to, dis[e.to]});
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) w[i] = read();
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read(), z = read();
        add(x, y, 0); add(x + n, y + n, 0);
        add(x + n * 2, y + n * 2, 0);
        add(x, y + n, -w[x]);
        add(x + n, y + n * 2, w[x]);
        if (z == 2) {
            add(y, x, 0); add(y + n, x + n, 0);
            add(y + n * 2, x + n * 2, 0);
            add(y, x + n, -w[y]);
            add(y + n, x + n * 2, w[y]);
        }
    }
    add(n, 1 + n * 3, 0); add(n * 3, 1 + n * 3, 0);
    n = 1 + n * 3;
    Dijkstra(1);
    printf("%d\n", dis[n]);
    return 0;
}