/*************************************************************
 *  > File Name        : P1613.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/11 20:39:41
 *  > Algorithm        : 倍增
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 60;

bool G[maxn][maxn][65];
int dis[maxn][maxn];

int main() {
    memset(dis, 0x3f, sizeof(dis));
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        dis[u][v] = 1;
        G[u][v][0] = true;
    }
    for (int k = 1; k <= 64; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int l = 1; l <= n; ++l) 
                    if (G[i][j][k - 1] && G[j][l][k - 1]) {
                        G[i][l][k] = true;
                        dis[i][l] = 1;
                    }
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
    printf("%d\n", dis[1][n]);
    return 0;
}