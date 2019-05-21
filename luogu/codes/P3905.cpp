/*************************************************************
 *  > File Name        : P3905.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/21 12:47:57
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int h[110][110], d[110][110];

int main() {
    memset(h, 0x3f, sizeof(h));
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        d[u][v] = d[v][u] = read();
        h[u][v] = h[v][u] = 0;
    }
    int k = read();
    for (int i = 1; i <= k; ++i) {
        int u = read(), v = read();
        h[u][v] = h[v][u] = d[u][v];
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
            }
        }
    }
    printf("%d\n", h[read()][read()]);
    return 0;
}