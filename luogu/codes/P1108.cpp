/*************************************************************
 *  > File Name        : P1108.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/20 12:44:34
 *  > Algorithm        : [DP]LIS
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5010;

int dp[maxn], a[maxn], f[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    int ans1 = 0, ans2 = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] < a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans1 = max(ans1, dp[i]);
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] == 1) f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (dp[i] == dp[j] + 1 && a[i] < a[j]) {
                f[i] += f[j];
            } else if (dp[i] == dp[j] && a[i] == a[j]) {
                f[i] = 0;
            }
        }
        if (dp[i] == ans1) ans2 += f[i];
    }

    printf("%d %d\n", ans1, ans2);
    return 0;
}