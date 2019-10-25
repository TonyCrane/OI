/*************************************************************
 *  > File Name        : c1079_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/25 12:22:39
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

const int maxn = 60;

int n, T, dp[maxn][maxn], ans;

struct Node {
    int c, h;
}a[maxn];
bool cmp(Node a, Node b) {
    return a.h < b.h;
}

int main() {
    n = read(); memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; ++i) a[i].c = read();
    for (int i = 1; i <= n; ++i) a[i].h = read();
    T = read();
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = a[i].c;
        if (a[i].c <= T) ans = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= i + 1; ++j) {
            for (int k = 1; k <= i - 1; ++k) {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + a[i].c + abs(a[i].h - a[k].h));
                if (dp[i][j] <= T) ans = max(ans, j);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}