/*************************************************************
 *  > File Name        : codevs1028.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/22 12:27:11
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int inf  = 0x3f3f3f3f;

int f, v, s, t, ansflow;
int vis[maxn], d[maxn], p[maxn], a[maxn];
long long anscost;

struct Edge {
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int c, int w) {
    edges.push_back(Edge(u, v, c, 0, w));
    edges.push_back(Edge(v, u, 0, 0,-w));
    int mm = edges.size();
    G[u].push_back(mm - 2);
    G[v].push_back(mm - 1);
}

bool BellmanFord(int& flow, long long& cost) {
    for (int i = 1; i <= f + v + 1; ++i) d[i] = inf;
    memset(vis, 0, sizeof(vis));
    d[s] = 0; vis[s] = 1; p[s] = 0; a[s] = inf;
    queue<int> Q;
    Q.push(s);
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        vis[x] = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (e.cap > e.flow && d[e.to] > d[x] + e.cost) {
                d[e.to] = d[x] + e.cost;
                p[e.to] = G[x][i];
                a[e.to] = min(a[x], e.cap - e.flow);
                if (!vis[e.to]) {
                    Q.push(e.to);
                    vis[e.to] = 1;
                }
            }
        }
    }
    if (d[t] == inf) return false;
    flow += a[t];
    cost += (long long)d[t] * (long long)a[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u] ^ 1].flow -= a[t];
    }
    return true;
}

int MinCostMaxFlow(long long& cost) {
    int flow = 0; cost = 0;
    while (BellmanFord(flow, cost));
    return flow;
}

int main() {
    scanf("%d %d", &f, &v);
    s = 0; t = f + v + 1;
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= v; ++j) {
            int c;
            scanf("%d", &c);
            add(i, f + j, 1, -c);
        }
    }
    for (int i = 1; i <= f; ++i) {
        add(s, i, 1, 0);
    }
    for (int i = 1; i <= v; ++i) {
        add(i + f, t, 1, 0);
    }
    ansflow = MinCostMaxFlow(anscost);
    printf("%lld\n", -anscost);
    return 0;
}