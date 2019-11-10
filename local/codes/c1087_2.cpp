/*************************************************************
 *  > File Name        : c1087_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/08 21:04:34
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int mod = 1e9 + 7;

int n, q, cnt, now;
int dp[2][1030], num[1030], sta[1030], ans[10];

int main() {
    for (int i = 0; i < 1024; ++i) {
        num[i] = num[i >> 1] + (i & 1);
        if (~num[i] & 1) sta[cnt++] = i;
    }
    int T = read();
    while (T--) {
        memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
        n = read(); q = read(); now = 0;
        while (q--) {
            char ch = getchar();
            while (ch != '-' && ch != '+') ch = getchar();
            int u = read() - 1, v = read() - 1;
            memset(ans, 0, sizeof(ans));
            int peo = (1 << u) | (1 << v);
            if (ch == '+') {
                for (int i = 0; i < cnt && sta[i] < (1 << n); ++i) {
                    dp[now ^ 1][sta[i]] = dp[now][sta[i]];
                    if ((sta[i] & peo) == peo) {
                        dp[now ^ 1][sta[i]] += dp[now][sta[i] ^ peo];
                        dp[now ^ 1][sta[i]] %= mod;
                    }
                    ans[num[sta[i]] / 2] += dp[now ^ 1][sta[i]];
                    ans[num[sta[i]] / 2] %= mod;
                }
            } else {
                for (int i = 0; i < cnt && sta[i] < (1 << n); ++i) {
                    dp[now ^ 1][sta[i]] = dp[now][sta[i]];
                    if ((sta[i] & peo) == peo) {
                        dp[now ^ 1][sta[i]] -= dp[now][sta[i] ^ peo];
                        dp[now ^ 1][sta[i]] = (dp[now ^ 1][sta[i]] + mod) % mod;
                    }
                    ans[num[sta[i]] / 2] += dp[now ^ 1][sta[i]];
                    ans[num[sta[i]] / 2] %= mod;
                }
            }
            now ^= 1;
            for (int i = 1; i <= n / 2; ++i) {
                printf("%d ", ans[i]);
            }
            puts("");
        }
    }
    return 0;
}