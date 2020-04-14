/*************************************************************
 *  > File Name        : P2476.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/14 08:16:35
 *  > Algorithm        : dp+dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL mod = 1e9 + 7;

int k, num[10];
LL dp[16][16][16][16][16][6];

LL dfs(int a, int b, int c, int d, int e, int last) {
    if (dp[a][b][c][d][e][last]) return dp[a][b][c][d][e][last];
    LL res = 0;
    if (a) res += (a - (last == 2)) * dfs(a - 1, b, c, d, e, 1);
    if (b) res += (b - (last == 3)) * dfs(a + 1, b - 1, c, d, e, 2);
    if (c) res += (c - (last == 4)) * dfs(a, b + 1, c - 1, d, e, 3);
    if (d) res += (d - (last == 5)) * dfs(a, b, c + 1, d - 1, e, 4);
    if (e) res += e * dfs(a, b, c, d + 1, e - 1, 5);
    return dp[a][b][c][d][e][last] = res % mod;
}

int main() {
    k = read();
    for (int i = 1; i <= k; ++i) {
        int c = read();
        num[c]++;
    }
    for (int i = 1; i <= 5; ++i) {
        dp[0][0][0][0][0][i] = 1;
    }
    printf("%lld\n", dfs(num[1], num[2], num[3], num[4], num[5], 0));
    return 0;
}