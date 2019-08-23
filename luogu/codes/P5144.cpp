/*************************************************************
 *  > File Name        : P5144.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/23 12:35:33
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

int n, m;
int dp[110][1010], sum[1010];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        int w = read();
        sum[i] = sum[i - 1] ^ w;
    }
    for (int i = 1; i <= n; ++i) dp[1][i] = sum[i];
    for (int i = 2; i <= m; ++i) {
        for (int j = i; j <= n; ++j) {
            for (int k = i - 1; k < j; ++k) {
                dp[i][j] = max(dp[i - 1][k] + (sum[j] ^ sum[k]), dp[i][j]);
            }
        }
    }
    printf("%d\n", dp[m][n]);
    return 0;
}