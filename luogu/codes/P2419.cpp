/*************************************************************
 *  > File Name        : P2419.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 07:14:00
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

const int maxn = 110;

int n, m, G[maxn][maxn], ans;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u][v] = 1;
    }
    for (int k = 1; k <= n; ++k) 
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                G[i][j] |= G[i][k] & G[k][j];
    for (int i = 1; i <= n; ++i) {
        int cnt = 1;
        for (int j = 1; j <= n; ++j)
            if (i != j) cnt &= G[i][j] | G[j][i];
        ans += cnt;
    }
    printf("%d\n", ans);
    return 0;
}