/*************************************************************
 *  > File Name        : P3371_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 07:28:01
 *  > Algorithm        : review SPFA
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

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

int n, m, s, dis[maxn];
bool vis[maxn];
queue<int> q;

void SPFA(int s) {
    for (int i = 1; i <= n; ++i) dis[i] = 2147483647;
    memset(vis, 0, sizeof(vis));
    vis[s] = true; dis[s] = 0; q.push(s);
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
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    SPFA(s);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    puts("");
    return 0;
}