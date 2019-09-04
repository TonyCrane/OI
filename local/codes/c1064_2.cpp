/*************************************************************
 *  > File Name        : c1064_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/03 16:21:16
 *  > Algorithm        : Dijkstra
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
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}


bool vis[maxn];
int n, m, pre[maxn];
long long ans = 0, dis[maxn];

void SPFA(int s) {
    queue<int> q;
    memset(dis, 0x7f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    q.push(s); dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] >= dis[u] + e.val) {
                if (dis[e.to] > dis[u] + e.val) {
                    ans += e.val;
                    if (dis[e.to] != 0x7f7f7f7f) {
                        ans -= pre[e.to];
                    }
                    pre[e.to] = e.val;
                } else {
                    if (pre[e.to] > e.val) {
                        ans += e.val - pre[e.to];
                        pre[e.to] = e.val;
                    }
                }
                dis[e.to] = dis[u] + e.val;
                if (!vis[e.to]) {
                    vis[e.to] = true;
                    q.push(e.to);
                }
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
    int s = read();
    SPFA(s);
    printf("%lld\n", ans);
    return 0;
}