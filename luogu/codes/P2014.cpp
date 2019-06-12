/*************************************************************
 *  > File Name        : P2014.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/11 12:55:37
 *  > Algorithm        : [DP]Tree+Pack
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define max(a, b) a < b ? b : a

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 310;

int dp[maxn][maxn], s[maxn];
int n, m;
vector<int> son[maxn];

void DP(int x) {
    dp[x][0] = 0;
    for (int i = 0; i < son[x].size(); ++i) {
        int y = son[x][i];
        DP(y);
        for (int t = m; t >= 0; --t) {
            for (int j = t; j >= 0; --j) {
                if (t - j >= 0) {
                    dp[x][t] = max(dp[x][t], dp[x][t - j] + dp[y][j]);
                }
            }
        }
    }
    if (x != 0) {
        for (int t = m; t > 0; --t) {
            dp[x][t] = dp[x][t - 1] + s[x];
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(); s[i] = read();
        son[x].push_back(i);
    }
    memset(dp, 0xcf, sizeof(dp));
    DP(0);
    printf("%d\n", dp[0][m]);
    return 0;
}