/*************************************************************
 *  > File Name        : P4779_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 07:47:48
 *  > Algorithm        : 
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
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

struct heap {
    int u, d;
    bool operator < (const heap& a) const {
        return d > a.d;
    }
};

int n, m, dis[maxn];

void Dijkstra(int s) {
    priority_queue<heap> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push((heap){s, 0});
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != dis[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                q.push((heap){e.to, dis[e.to]});
            }
        }
    }
}

int main() {
    n = read(), m = read(); int s = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    Dijkstra(s);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    puts("");
    return 0;
}