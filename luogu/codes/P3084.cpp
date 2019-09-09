/*************************************************************
 *  > File Name        : P3084.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/09 12:38:53
 *  > Algorithm        : 差分约束
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

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

int n, m, tot = 0;
int dis[maxn], vis[maxn], cnt[maxn];

int SPFA(int s) {
    deque<int> q; q.push_back(s);
    memset(dis, 0x3f, sizeof(dis));
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
                    // cnt[e.to]++;
                }
                // if (cnt[e.to] > n) {
                //     return -1;
                // }
                if (++tot > 1926817) {
                    return -1;
                }
            }
        }
    }
    return dis[n];
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int a = read(), b = read();
        add(a - 1, b, 1);
        add(b, a - 1, -1);
    }
    for (int i = 1; i <= n; ++i) {
        add(i, i - 1, 0);
        add(i - 1, i, 1);
    }
    printf("%d\n", SPFA(0));
    return 0;
}