/*************************************************************
 *  > File Name        : P1594.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 12:32:55
 *  > Algorithm        : DP 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

long long maxw, l, n, w[maxn], v[maxn], sum[maxn], minv[maxn][maxn];
double dp[maxn];

int main() {
    maxw = read(); l = read(); n = read();
    for (int i = 1; i <= n; ++i) {
        w[i] = read(); v[i] = read();
        sum[i] = sum[i - 1] + w[i];
        minv[i][i] = v[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            minv[i][j] = min(v[j], minv[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = (double)l / v[i] + dp[i - 1];
        for (int j = i - 1; j >= 1; --j) {
            if (sum[i] - sum[j - 1] <= maxw) {
                dp[i] = min(dp[i], dp[j - 1] + (double)l / minv[j][i]);
            } else break;
        }
    }
    printf("%.1lf", dp[n] * 60);
    return 0;
}