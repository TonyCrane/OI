/*************************************************************
 *  > File Name        : P1772.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/17 15:33:47
 *  > Algorithm        : SPFA + DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

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

int n, m, K, e, d;
int dis[maxn], dp[maxn], tab[maxn][maxn];
bool vis[maxn], valid[maxn];

void SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0; vis[s] = true;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val && !valid[e.to]) {
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
    n = read(); m = read(); K = read(); e = read();
    for (int i = 1; i <= e; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    d = read();
    for (int i = 1; i <= d; ++i) {
        int p = read(), a = read(), b = read();
        for (int j = a; j <= b; ++j) {
            tab[p][j] = true;
        }
    }
    memset(dp, 0x3f, sizeof(dp)); dp[0] = -K;
    for (int i = 1; i <= n; ++i) {
        memset(valid, 0, sizeof(valid));
        for (int j = i; j >= 1; --j) {
            for (int k = 1; k <= m; ++k) {
                if (tab[k][j]) valid[k] = true;
            }
            SPFA(1);
            if (dis[m] == 0x3f3f3f3f) break;
            dp[i] = min(dp[i], dp[j - 1] + (i - j + 1) * dis[m] + K);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}