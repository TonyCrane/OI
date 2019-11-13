/*************************************************************
 *  > File Name        : c1090_2.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 20:59:00
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 80;

struct Edge {
    LL from, to;
}edges[150];

LL n, m, w[maxn], G[maxn][maxn], dis[maxn][maxn];
LL ans1 = 0, ans2 = -0x3f3f3f3f;

int main() {
    n = read(); m = read();
    for (LL i = 1; i <= n; ++i) {
        w[i] = read();
    }
    memset(G, 0x3f, sizeof(G));
    for (LL i = 1; i <= n; ++i) G[i][i] = 0;
    for (LL i = 1; i <= m; ++i) {
        LL u = read(), v = read(), opt = read();
        G[u][v] = 1;
        G[v][u] = 1;
        edges[i].from = u;
        edges[i].to   = v;
    }
    for (LL i = 1; i <= n; ++i) {
        for (LL j = 1; j <= n; ++j) {
            dis[i][j] = G[i][j];
        }
    }
    for (LL k = 1; k <= n; ++k) {
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (LL i = 1; i <= n; ++i) {
        for (LL j = 1; j <= n; ++j) {
            if (dis[i][j] != 0x3f3f3f3f && i != j) {
                ans1 += dis[i][j] + w[j];
            } 
        }
    }
    for (LL del = 1; del <= m; ++del) {
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= n; ++j) {
                dis[i][j] = G[i][j];
            }
        }
        dis[edges[del].from][edges[del].to] = dis[edges[del].to][edges[del].from] = 0x3f3f3f3f3f3f3f3f;
        for (LL k = 1; k <= n; ++k) {
            for (LL i = 1; i <= n; ++i) {
                for (LL j = 1; j <= n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        LL res = 0;
        for (LL i = 1; i <= n; ++i) {
            for (LL j = 1; j <= n; ++j) {
                if (dis[i][j] != 0x3f3f3f3f3f3f3f3f && i != j) {
                    res += dis[i][j] + w[j];
                } 
            }
        }
        ans2 = max(ans2, res);
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}