/*************************************************************
 *  > File Name        : P1352.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/12 12:30:34
 *  > Algorithm        : [DP]Tree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define max(a, b) a < b ? b : a

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 6010;

int dp[2][maxn];
int r[maxn], vis[maxn];
vector<int> son[maxn];

void DP(int x) {
    dp[0][x] = 0;
    dp[1][x] = r[x];
    for (int i = 0; i < son[x].size(); ++i) {
        int y = son[x][i];
        DP(y);
        dp[0][x] += max(dp[0][y], dp[1][y]);
        dp[1][x] += dp[0][y];
    }
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) r[i] = read();
    for (int i = 1; i <  n; ++i) {
        int l = read(), k = read();
        son[k].push_back(l);
        vis[l] = 1;
    }
    int root;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            root = i; break;
        }
    }
    DP(root);
    printf("%d\n", max(dp[0][root], dp[1][root]));
    return 0;
}