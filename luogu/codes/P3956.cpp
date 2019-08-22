/*************************************************************
 *  > File Name        : P3956.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/22 15:17:05
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

const int maxm = 110;
const int inf  = 0x3f3f3f3f;

int n, m, ans;
int G[maxm][maxm];
int best[maxm][maxm];
int go[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool check(int x, int y) {
    return x > 0 && x <= m && y > 0 && y <= m && G[x][y];
}

void dfs(int x, int y, int now, int magic) {
    if (now >= best[x][y]) return;
    best[x][y] = now;
    if (x == m && y == m) {
        ans = min(ans, now);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if (G[nx][ny] && check(nx, ny)) {
            if (G[nx][ny] == G[x][y]) {
                dfs(nx, ny, now, false);
            } else {
                dfs(nx, ny, now + 1, false);
            }
        } else if (!magic) {
            G[nx][ny] = G[x][y];
            if (check(nx, ny)) {
                dfs(nx, ny, now + 2, true);
            }
            G[nx][ny] = 0;
        }
    }
}

int main() {
    m = read(); n = read();
    memset(best, 0x3f, sizeof(best)); ans = inf;
    for (int i = 1; i<= n; ++i) {
        int x = read(), y = read(), z = read();
        G[x][y] = z + 1;
    }
    dfs(1, 1, 0, false);
    if (ans == inf) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}