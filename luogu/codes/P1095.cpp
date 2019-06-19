/*************************************************************
 *  > File Name        : P1095.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/19 16:07:42
 *  > Algorithm        : [Simulation]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 300010;

int dp[maxn];

int main() {
    int m = read(), s = read(), t = read(); dp[0] = 0;
    for (int i = 1; i <= t; ++i) {
        if (m >= 10) {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        } else {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t; ++i) {
        if (dp[i] < dp[i - 1] + 17) dp[i] = dp[i - 1] + 17;
        if (dp[i] >= s) {
            printf("Yes\n%d\n", i);
            return 0;
        }
    }
    printf("No\n%d\n", dp[t]);
    return 0;
}