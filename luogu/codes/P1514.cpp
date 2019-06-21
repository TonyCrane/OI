/*************************************************************
 *  > File Name        : P1514.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/21 15:10:31
 *  > Algorithm        : [Dfs]Ex
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 510;

int n, m;
int high[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn];
bool vis[maxn][maxn];

int go[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int x2 = x + go[i][0];
        int y2 = y + go[i][1];
        if (x2 < 1 || x2 > n || y2 < 1 || y2 > m || high[x2][y2] >= high[x][y]) continue;
        if (!vis[x2][y2]) dfs(x2, y2);
        l[x][y] = min(l[x][y], l[x2][y2]);
        r[x][y] = max(r[x][y], r[x2][y2]);
    }
}

int main() {
    n = read(); m = read();
    memset(l, 0x3f, sizeof(l));
    for (int i = 1; i <= m; ++i) {
        l[n][i] = r[n][i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            high[i][j] = read();
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (!vis[1][i]) {
            dfs(1, i);
        }
    }
    bool flg = true; int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        if (!vis[n][i]) {
            flg = false;
            cnt++;
        }
    }
    if (!flg) {
        printf("0\n%d\n", cnt);
        return 0;
    }
    int le = 1, ans = 0;
    while (le <= m) {
        int tmp = 0;
        for (int i = 1; i <= m; ++i) {
            if (l[1][i] <= le) {
                tmp = max(tmp, r[1][i]);
            }
        }
        ans++;
        le = tmp + 1;
    }
    printf("1\n%d\n", ans);
    return 0;
}