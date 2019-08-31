/*************************************************************
 *  > File Name        : P1993.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/31 15:19:12
 *  > Algorithm        : [SPFA]差分约束系统
**************************************************************/

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;
const int inf  = 0x3f3f3f3f;

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

int n, m;
int dis[maxn], vis[maxn], cnt[maxn];

bool SPFA(int s) {
    deque<int> q; q.push_back(s);
    dis[s] = 0; vis[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop_front(); vis[u] = false;
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
                    cnt[e.to]++;
                }
                if (cnt[e.to] > n) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int opt = read();
        if (opt == 1) {
            int a = read(), b = read(), c = read();
            add(a, b, -c);
        } else if (opt == 2) {
            int a = read(), b = read(), c = read();
            add(b, a, c);
        } else {
            int a = read(), b = read();
            add(a, b, 0); add(b, a, 0);
        }
    }
    for (int i = 1; i <= n; ++i) {
        add(0, i, 0);
        dis[i] = inf;
    }
    printf(SPFA(0) ? "Yes\n" : "No\n");
    return 0;
}