/*************************************************************
 *  > File Name        : P2059.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/13 21:11:37
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

const int maxn = 60;

int n, m, a[maxn];
double dp[maxn][maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        a[i] = read();
    }
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int peo;
            if (a[j] % i == 0) peo = i;
            else peo = a[j] % i;
            for (int k = 1; k <= i - 1; ++k) {
                peo++;
                if (peo > i) peo = 1;
                dp[i][peo] += dp[i - 1][k] / (double)m;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%.2lf%% ", dp[n][i] * 100);
    }
    puts("");
    return 0;
}