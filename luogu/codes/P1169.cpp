/*************************************************************
 *  > File Name        : P1169.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/07 12:29:53
 *  > Algorithm        : DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2010;

int n, m, ans1, ans2;
int G[maxn][maxn], l[maxn][maxn], r[maxn][maxn], u[maxn][maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            G[i][j] = read();
            l[i][j] = r[i][j] = j;
            u[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            if (G[i][j] != G[i][j - 1]) {
                l[i][j] = l[i][j - 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m - 1; j; --j) {
            if (G[i][j] != G[i][j + 1]) {
                r[i][j] = r[i][j + 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i > 1 && G[i][j] != G[i - 1][j]) {
                l[i][j] = max(l[i][j], l[i - 1][j]);
                r[i][j] = min(r[i][j], r[i - 1][j]);
                u[i][j] = u[i - 1][j] + 1;
            }
            int a = r[i][j] - l[i][j] + 1;
            int b = min(a, u[i][j]);
            ans1 = max(ans1, b * b);
            ans2 = max(ans2, a * u[i][j]);
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}