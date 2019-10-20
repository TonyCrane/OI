/*************************************************************
 *  > File Name        : P2593.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 13:56:22
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

const int maxn = 110;

int a[maxn];
bool dp[maxn][maxn][maxn][2];

int main() {
    int T = read();
    while (T--) {
        for (int i = 1; i <= 100; ++i) {
            a[i] = read();
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;
        for (int i = 1; i <= 100; ++i) {
            for (int j = 0; j <= a[i - 1]; ++j) {
                for (int k = 0; k <= a[i]; ++k) {
                    if (k >= 2) dp[i][j][k][1] = dp[i][j][k][1] | dp[i][j][k - 2][0];
                    if (k >= 3) {
                        dp[i][j][k][1] = dp[i][j][k][1] | dp[i][j][k - 3][1];
                        dp[i][j][k][0] = dp[i][j][k][0] | dp[i][j][k - 3][0];
                    }
                    if (k >= 4) {
                        dp[i][j][k][1] = dp[i][j][k][1] | dp[i][j][k - 4][1];
                        dp[i][j][k][0] = dp[i][j][k][0] | dp[i][j][k - 4][0];
                    }
                    if (j >= k && a[i - 2] >= k) {
                        dp[i][j][k][1] = dp[i][j][k][1] | dp[i - 1][a[i - 2] - k][j - k][1];
                        dp[i][j][k][0] = dp[i][j][k][0] | dp[i - 1][a[i - 2] - k][j - k][0];
                    }
                }
            }
        }
        printf(dp[100][a[99]][a[100]][1] ? "Yes\n" : "No\n");
    }
    return 0;
}