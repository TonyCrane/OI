/*************************************************************
 *  > File Name        : P1144.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/21 12:33:38
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;
const int mod  = 100003;

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

int dist[maxn], vis[maxn];
int n, m, w, ans[maxn];

void SPFA(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0; vis[s] = 1; ans[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dist[e.to] > dist[u] + 1) {
                dist[e.to] = dist[u] + 1;
                ans[e.to] = ans[u];
                if (!vis[e.to]) {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            } else if (dist[e.to] == dist[u] + 1) {
                ans[e.to] += ans[u];
                ans[e.to] %= mod;
            }
        }
    }
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        add(x, y);
    }
    memset(dist, 0x7f, sizeof(dist));
    SPFA(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}