/*************************************************************
 *  > File Name        : P1736.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/19 15:50:46
 *  > Algorithm        : [DP]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2510;

int n, m, ans;
int in[maxn][maxn], dp[maxn][maxn], row[maxn][maxn], col[maxn][maxn];

void init() {
    memset(dp, 0, sizeof(dp));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            in[i][j] = read();
            if (!in[i][j]) {
                row[i][j] = row[i][j - 1] + 1;
                col[i][j] = col[i - 1][j] + 1;
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(row[i][j - 1], col[i - 1][j])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    init();
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) {
            if (!in[i][j]) {
                row[i][j] = row[i][j + 1] + 1;
                col[i][j] = col[i - 1][j] + 1;
            } else {
                dp[i][j] = min(dp[i - 1][j + 1], min(row[i][j + 1], col[i - 1][j])) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}