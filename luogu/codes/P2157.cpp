/*************************************************************
 *  > File Name        : P2157.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/11 15:08:32
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

const int maxn = 1010;
const int maxs = 1 << 8;
const int inf  = 0x3f3f3f3f;

int dp[maxn][maxs][20];
int t[maxn], b[maxn], tab[20], n;

int main() {
    int T = read();
    while (T--) {
        n = read(); memset(dp, 0x3f, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            t[i] = read(), b[i] = read();
        }
        dp[1][0][7] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < (1 << 8); ++j) {
                for (int k = -8; k <= 7; ++k) {
                    if (dp[i][j][k + 8] == inf) continue;
                    if (j & 1) {
                        dp[i + 1][j >> 1][k + 7] = min(dp[i + 1][j >> 1][k + 7], dp[i][j][k + 8]);
                    } else {
                        int m = inf;
                        for (int l = 0; l <= 7; ++l) {
                            if ((j >> l) & 1) continue;
                            if (i + l > m) break;
                            m = min(m, i + l + b[i + l]);
                            dp[i][j | (1 << l)][l + 8] = min(dp[i][j | (1 << l)][l + 8], dp[i][j][k + 8] + ((i + k) ? (t[i + k] ^ t[i + l]) : 0));
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int i = 0; i <= 8; ++i) {
            ans = min(ans, dp[n + 1][0][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}