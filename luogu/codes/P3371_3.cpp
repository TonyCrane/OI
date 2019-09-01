/*************************************************************
 *  > File Name        : P3371_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/01 14:12:37
 *  > Algorithm        : SPFA with SLF
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

int dis[maxn];
bool vis[maxn];

void SPFA(int s) {
    deque<int> q; q.push_back(s);
    dis[s] = 0; vis[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop_front(); 
        vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                if (!vis[e.to]) {
                    vis[e.to] = true;
                    if (!q.empty() && dis[e.to] < dis[q.front()]) {
                        q.push_front(e.to);
                    } else {
                        q.push_back(e.to);
                    }
                }
            }
        }
    }
}

int main() {
    int n = read(), m = read(), s = read();
    for (int i = 1; i<= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    for (int i = 1; i <= n; ++i) {
        dis[i] = 2147483647;
    }
    SPFA(s);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dis[i]);
    }
    return 0;
}