/*************************************************************
 *  > File Name        : c1062_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/19 12:47:05
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

const int maxn = 1010;
const int inf  = 0x3f3f3f3f;

bool G[maxn][maxn], vis[maxn][maxn];
int ans[maxn][maxn];
int sx, sy, tx, ty, n;
int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Node {
    int x, y;
};

bool check(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n && !G[x][y] && !vis[x][y];
}

void bfs() {
    vis[sx][sy] = true;
    queue<Node> q;
    q.push((Node){sx, sy});
    ans[sx][sy] = 0;
    while (!q.empty()) {
        Node top = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = top.x + go[i][0];
            int ny = top.y + go[i][1];
            if (check(nx, ny)) {
                ans[nx][ny] = ans[top.x][top.y] + 1;
                vis[nx][ny] = true;
                q.push((Node){nx, ny});
            }
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = read();
            G[i][j] = (bool)x;
        }
    }
    sx = read(); sy = read(); tx = read(); ty = read();
    memset(ans, -1, sizeof(ans));
    bfs();
    printf("%d\n", ans[tx][ty]);
    return 0;
}