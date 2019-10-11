/*************************************************************
 *  > File Name        : P2327.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/11 21:32:14
 *  > Algorithm        : DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
inline int read() { int x = 0; int f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();} return x * f; }
const int maxn = 10010; int n, a[maxn], dp[maxn][2][2];
int main() { n = read(); for (int i = 1; i <= n; ++i) a[i] = read(); dp[0][0][0] = dp[0][0][1] = 1;
    for (int i = 1; i <= n; ++i) { if (a[i] == 0) dp[i][0][0] += dp[i - 1][0][0];
        if (a[i] == 1) { dp[i][0][0] += dp[i - 1][1][0]; dp[i][1][0] += dp[i - 1][0][1]; dp[i][0][1] += dp[i - 1][0][0]; }
        if (a[i] == 2) { dp[i][1][1] += dp[i - 1][0][1]; dp[i][0][1] += dp[i - 1][1][0]; dp[i][1][0] += dp[i - 1][1][1]; }
        if (a[i] == 3) dp[i][1][1] += dp[i - 1][1][1]; }
    printf("%d\n", dp[n][0][0] + dp[n][1][0]); return 0;
}