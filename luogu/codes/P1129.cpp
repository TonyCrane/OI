/*************************************************************
 *  > File Name        : P1129.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/05 15:56:03
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 250;
const int inf  = 0x3f3f3f3f;

int n, m, s, t;
int d[maxn], cur[maxn];
bool vis[maxn];

struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int c) {
    edges.push_back(Edge(u, v, c, 0));
    edges.push_back(Edge(v, u, 0, 0));
    int mm = edges.size();
    G[u].push_back(mm - 2);
    G[v].push_back(mm - 1);
}

bool bfs() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s); d[s] = 0; vis[s] = true;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!vis[e.to] && e.cap > e.flow) {
                vis[e.to] = true;
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

int maxflow(int s, int t) {
    int flow = 0;
    while (bfs()) {
        memset(cur, 0, sizeof(cur));
        flow += dfs(s, inf);
    }
    return flow;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(d, 0, sizeof(d));
        memset(cur, 0, sizeof(cur));
        memset(vis, 0, sizeof(vis));
        edges.clear();
        for (int i = 0; i <= 200; ++i) {
            G[i].clear();
        }
        scanf("%d", &n);
        s = 0; t = 2 * n + 1;
        for (int i = 1; i <= n; ++i) {
            add(s, i, 1);
            add(i + n, t, 1);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                int tmp;
                scanf("%d", &tmp);
                if (tmp) {
                    add(i, j + n, 1);
                }
            }
        }
        if (maxflow(s, t) == n) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}