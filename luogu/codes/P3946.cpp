/*************************************************************
 *  > File Name        : P3946.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/22 12:44:27
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int inf  = 0x3f3f3f3f;
const int maxn = 100010;

int n, m, s, t, g, q, ans;
int h[maxn], l[maxn];
int dis[maxn], vis[maxn], limit[maxn];

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

bool SPFA(int s, int t) {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    q.push(s); vis[s] = 1; dis[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (  (   dis[e.to] > dis[u] + e.val 
                   && dis[u] + e.val < limit[e.to]
                   && e.to != t                   ) ||
                  (   dis[e.to] > dis[u] + e.val
                   && e.to == t                   )  ) {
                dis[e.to] = dis[u] + e.val;
                if (!vis[e.to]) {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
    ans = dis[t];
    if (ans == inf) return false;
    else return true;
}

int main() {
    n = read(), m = read(), s = read(), t = read(), g = read(), q = read();
    for (int i = 1; i <= n; ++i) {
        h[i] = read(); l[i] = read();
    }
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    // Pretreatment limited time
    for (int i = 1; i <= n; ++i) {
        if (q == 0) limit[i] = inf;
        else limit[i] = (int)((double)(l[i] - h[i]) / (double)(q));
    }
    if (SPFA(s, t) && ans <= g) {
        printf("%d\n", ans);
    } else {
        printf("wtnap wa kotori no oyatsu desu!\n");
    }
    return 0;
}