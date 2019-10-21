/*************************************************************
 *  > File Name        : P2384.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/21 21:24:47
 *  > Algorithm        : Dijkstra 记录路径
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;
const int mod  = 9987;

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
    int u; double d;
    heap(int u, double d): u(u), d(d) {}
    bool operator < (const heap& a) const {
        return d > a.d;
    }
};

int n, m, pre[maxn][2];
double dis[maxn];

void Dijkstra(int s) {
    priority_queue<heap> q;
    memset(dis, 127, sizeof(dis));
    dis[s] = 0.0; q.push(heap(s, 0.0));
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u; double td = top.d;
        if (td != dis[u]) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + log(e.val)) {
                dis[e.to] = dis[u] + log(e.val);
                q.push(heap(e.to, dis[e.to]));
                pre[e.to][0] = u;
                pre[e.to][1] = e.val;
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    Dijkstra(1);
    int ans = 1, pos = n;
    while (pos != 1) {
        ans *= pre[pos][1];
        ans %= mod;
        pos = pre[pos][0];
    }
    printf("%d\n", ans);
    return 0;
}