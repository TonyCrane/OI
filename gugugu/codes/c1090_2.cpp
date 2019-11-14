/*************************************************************
 *  > File Name        : c1090_2.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 20:59:00
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

const int maxn = 80;

struct Edge {
    int from, to;
}edges[150];

int n, m, w[maxn], G[maxn][maxn], dis[maxn][maxn];
int ans1 = 0, ans2 = 0;
bool vis[maxn];

void dfs(int u) {
    vis[u] = true;
    for (int i = 1; i <= n; ++i) {
        if (dis[u][i] != 0x3f3f3f3f && !vis[i]) dfs(i);
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        w[i] = read();
    }
    memset(G, 0x3f, sizeof(G));
    for (int i = 1; i <= n; ++i) G[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), opt = read();
        G[u][v] = 1;
        G[v][u] = 1;
        edges[i].from = u;
        edges[i].to   = v;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dis[i][j] = G[i][j];
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dis[i][j] != 0x3f3f3f3f && i != j) {
                ans1 += dis[i][j] + w[j];
            }
        }
    }
    for (int del = 1; del <= m; ++del) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = G[i][j];
            }
        }
        dis[edges[del].from][edges[del].to] = dis[edges[del].to][edges[del].from] = 0x3f3f3f3f;
        memset(vis, 0, sizeof(vis));
        dfs(1); bool connected = true;
        for (int i = 1; i <= n; ++i) if (!vis[i]) connected = false;
        if (!connected) break;
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dis[i][j] != 0x3f3f3f3f && i != j) {
                    res += dis[i][j] + w[j];
                }
            }
        }
        ans2 = max(ans2, res);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}