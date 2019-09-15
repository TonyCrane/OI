/*************************************************************
 *  > File Name        : P3275.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/15 15:11:36
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

const int maxn = 100010;
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

int n, k;
long long ans = 0;
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
    n = read(); k = read();
    for (int i = 1; i <= k; ++i) {
        int x = read(), a = read(), b = read();
        if (x == 1) add(b, a, 0), add(a, b, 0);
        else if (x == 2) add(a, b, -1);
        else if (x == 3) add(b, a, 0);
        else if (x == 4) add(b, a, -1);
        else if (x == 5) add(a, b, 0);
    }
    for (int i = 1; i <= n; ++i) {
        add(0, i, -1);
        dis[i] = inf;
    }
    if (!SPFA(0)) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        ans -= dis[i];
    }
    printf("%lld\n", ans);
    return 0;
}