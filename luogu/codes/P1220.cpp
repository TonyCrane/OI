/*************************************************************
 *  > File Name        : P1220.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/30 15:09:56
 *  > Algorithm        : dp
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

int n, c;
int pos[maxn], w[maxn], dp[maxn][maxn][2];

int sum(int a, int b) {
    return w[n] - w[b] + w[a];
}

int dis(int a, int b) {
    return pos[b] - pos[a];
}

int main() {
    n = read(); c = read();
    for (int i = 1; i <= n; ++i) {
        pos[i] = read();
        w[i] = w[i - 1] + read();
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[c][c][0] = dp[c][c][1] = 0;
    for (int j = c; j <= n; ++j) {
        for (int i = j - 1; i > 0; --i) {
            int tmp0 = dp[i + 1][j][0] + sum(i, j) * dis(i, i + 1);
            int tmp1 = dp[i + 1][j][1] + sum(i, j) * dis(i, j);
            dp[i][j][0] = min(tmp0, tmp1);
            tmp0 = dp[i][j - 1][0] + sum(i - 1, j - 1) * dis(i, j);
            tmp1 = dp[i][j - 1][1] + sum(i - 1, j - 1) * dis(j - 1, j);
            dp[i][j][1] = min(tmp0, tmp1);
        }
    }
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
    return 0;
}