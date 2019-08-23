/*************************************************************
 *  > File Name        : P2196.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/23 12:44:37
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int num[30], ans[30], now[30];
bool vis[30], G[30][30];
int n, ansn, cnt;

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        if (G[x][i] && !vis[i]) return false;
    }
    return true;
}

void dfs(int pos, int step, int sum) {
    if (check(pos)) {
        if (ansn < sum) {
            ansn = sum;
            cnt = step;
            for (int i = 1; i <= step; ++i) {
                ans[i] = now[i];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (G[pos][i] && !vis[i]) {
            vis[i] = true;
            now[step + 1] = i;
            dfs(i, step + 1, sum + num[i]);
            vis[i] = false;
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) num[i] = read();
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int x = read();
            G[i][j] = (bool)x;
        }
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = true;
        now[1] = i;
        dfs(i, 1, num[i]);
        vis[i] = false;
    }
    for (int i = 1; i <= cnt; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n%d\n", ansn);
    return 0;
}