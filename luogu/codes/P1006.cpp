/*************************************************************
 *  > File Name        : P1006.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/17 12:27:08
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

int dp[maxn][maxn][maxn][maxn], a[maxn][maxn];

int main() {
    int m = read(), n = read();
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = read();
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= m; ++k) {
                for (int l = j + 1; l <= n; ++l) {
                    dp[i][j][k][l] = max(dp[i][j - 1][k][l - 1], \
                                     max(dp[i][j - 1][k - 1][l], \
                                     max(dp[i - 1][j][k - 1][l], \
                                         dp[i - 1][j][k][l - 1]))) \
                                         + a[i][j] + a[k][l];
                }
            }
        }
    }
    printf("%d\n", max(dp[m][n - 1][m - 1][n], dp[m - 1][n][m][n - 1] + a[m][n]));
    return 0;
}