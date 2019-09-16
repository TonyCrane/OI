/*************************************************************
 *  > File Name        : c1065_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/16 13:00:33
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
int n, T, sum[maxn], dp[maxn];

int main() {
    n = read(); T = read();
    for (int i = 1; i <= n; ++i) {
        int v = read();
        sum[i] = sum[i - 1] + v;
    }
    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = min(dp[i], dp[j - 1] + (sum[i] - sum[j - 1] - T) * (sum[i] - sum[j - 1] - T));
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}