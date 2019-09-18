/*************************************************************
 *  > File Name        : c1065_2_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/18 15:27:49
 *  > Algorithm        : SPFA
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

int n, T, v, sum[maxn];

int dis[maxn];
bool vis[maxn];
void SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0; vis[s] = true;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                if (!vis[e.to]) {
                    q.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
}

int main() {
    n = read(); T = read();
    for (int i = 1; i <= n; ++i) {
        v = read();
        sum[i] = sum[i - 1] + v;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int w = (sum[j] - sum[i] - T) * (sum[j] - sum[i] - T);
            add(i, j, w);
        }
    }
    for (int i = 1; i <= n; ++i) {
        int w = (sum[i] - T) * (sum[i] - T);
        add(0, i, w);
    }
    SPFA(0);
    printf("%d\n", dis[n]);
    return 0;
}