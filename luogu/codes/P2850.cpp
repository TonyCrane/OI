/*************************************************************
 *  > File Name        : P2850.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/17 15:44:20
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 510;

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

int dist[maxn], vis[maxn], cnt[maxn];
int n, m, w;

bool SPFA(int s) {
    queue<int> q;
    q.push(s);
    dist[s] = 0; vis[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dist[e.to] > dist[u] + e.val) {
                dist[e.to] = dist[u] + e.val;
                if (!vis[e.to]) {
                    vis[e.to] = 1;
                    q.push(e.to);
                    cnt[e.to]++;
                }
                if (cnt[e.to] > n) {
                    return true;
                }
            }
        }
    }
    return false;
}

void clear() {
    edges.clear();
    for (int i = 0; i < maxn - 5; ++i) {
        G[i].clear();
    }
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x7f, sizeof(dist));
}

int main() {
    int T = read();
    while (T--) {
        clear();
        n = read(); m = read(); w = read();
        for (int i = 0; i < m; ++i) {
            int u = read(), v = read(), d = read();
            add(u, v, d); add(v, u, d);
        }
        for (int i = 0; i < w; ++i) {
            int u = read(), v = read(), d = read();
            add(u, v, -d);
        }
        if (SPFA(1)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}