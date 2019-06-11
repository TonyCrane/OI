/*************************************************************
 *  > File Name        : P1336.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/11 12:14:26
 *  > Algorithm        : [DP]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define min(a, b) a < b ? a : b

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 25;

int n, m;
int a[maxn], b[maxn];
int dp[2010];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        a[i] = read(); b[i] = read();
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = n; j >= 1; --j) {
            for (int k = j; k >= 1; --k) {
                dp[j] = min(dp[j], dp[j - k] + a[i] * pow(k, b[i]));
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}