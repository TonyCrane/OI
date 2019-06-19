/*************************************************************
 *  > File Name        : P2740.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/17 12:36:43
 *  > Algorithm        : [Graph]MaxFlow
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 210;

int n, m, s, t, d[maxn], cur[maxn];
struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    int mm = edges.size();
    G[from].push_back(mm - 2);
    G[to].push_back(mm - 1);
}

bool vis[maxn];

bool bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!vis[e.to] && e.cap > e.flow) {
                vis[e.to] = 1;
                d[e.to] = d[x] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}

int dfs(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[G[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0) break;
        }
    }
    return flow;
}

int MaxFlow(int s, int t) {
    int flow = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(s, 0x3f3f3f3f);
    }
    return flow;
}

int main() {
    m = read(); n = read();
    s = 1; t = n;
    for (int i = 1; i <= m; ++i) {
        int si = read(), ei = read(), ci = read();
        add(si, ei, ci);
    }
    printf("%d\n", MaxFlow(s, t));
    return 0;
}