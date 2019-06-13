/*************************************************************
 *  > File Name        : P2016.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/13 12:56:03
 *  > Algorithm        : [DP]Tree
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

const int maxn = 1510;

int dp[2][maxn];
vector<int> son[maxn];

void DP(int x) {
    dp[1][x] = 1;
    dp[0][x] = 0;
    for (int i = 0; i < son[x].size(); ++i) {
        int y = son[x][i];
        DP(y);
        dp[0][x] += dp[1][y];
        dp[1][x] += min(dp[1][y], dp[0][y]);
    }
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(), k = read();
        for (int j = 1; j <= k; ++j) {
            int y = read();
            son[x].push_back(y);
        }
    }
    DP(0);
    printf("%d\n", min(dp[0][0], dp[1][0]));
    return 0;
}