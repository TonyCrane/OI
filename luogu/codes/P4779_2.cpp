/*************************************************************
 *  > File Name        : P4779_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/17 16:18:22
 *  > Algorithm        : [Graph]Dijkstra+Heap
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

struct Edge {
    int from, to, dis;
    Edge(int u, int v, int w): from(u), to(v), dis(w) {}
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

int n, m, d[maxn];

void Dijkstra(int s) {
    priority_queue<heap> q;
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    q.push((heap){s, 0});
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != d[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.dis) {
                d[e.to] = d[u] + e.dis;
                q.push((heap){e.to, d[e.to]});
            }
        }
    }
}

int main() {
    n = read(), m = read();
    int s = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    Dijkstra(s);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", d[i]);
    }
    puts("");
    return 0;
}