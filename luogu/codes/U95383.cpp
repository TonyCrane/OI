/*************************************************************
 *  > File Name        : U95383.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 14:34:51
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
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

int n, m, Q;
int dis[maxn];
bool vis[maxn];

void SPFA(int s) {
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0; vis[s] = true;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] == -1 || dis[e.to] > dis[u] ^ e.val) {
                dis[e.to] = dis[u] ^ e.val;
                if (!vis[e.to]) {
                    q.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
}

int main() {
    n = read(), m = read(), Q = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    SPFA(1);
    for (int i = 1; i <= Q; ++i) {
        int s = read(), t = read();
        printf("%d\n", dis[s] ^ dis[t]);
    }
    return 0;
}