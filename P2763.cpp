/*************************************************************
 *  > File Name        : P2763.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/04/05 13:59:22
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2020;
const int inf  = 0x3f3f3f3f;

bool vis[maxn];
int k, n, s, t, sum, d[maxn], cur[maxn];
int ans[maxn], ansi;
struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
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
    Q.push(s);
    d[s] = 0; vis[s] = true;
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
        flow += dfs(s, inf);
    }
    return flow;
}

int main() {
    scanf("%d %d", &k, &n);
    s = 0; t = n + k + 1;
    for (int i = 1; i <= k; ++i) {
        int type;
        scanf("%d", &type);
        sum += type; add(n + i, t, type);
    }
    for (int i = 1; i <= n; ++i) {
        add(s, i, 1);
        int p, type;
        scanf("%d", &p);
        for (int j = 1; j <= p; ++j) {
            scanf("%d", &type);
            add(i, type + n, 1);
        }
    }
    int maxflow = MaxFlow(s, t);
    if (maxflow == sum) {
        for (int i = n + 1; i <= n + k; ++i) {
            ansi = 0;
            printf("%d: ", i - n);
            for (int j = 0; j < G[i].size(); ++j) {
                Edge& e = edges[G[i][j]];
                if (e.flow == 0) ans[++ansi] = e.to;
            }
            for (int j = 1; j <= ansi; ++j) {
                if (j == 1) printf("%d", ans[j]);
                else printf(" %d", ans[j]);
            }
            printf("\n");
        }
    } else {
        printf("No Solution!\n");
    }
    return 0;
}