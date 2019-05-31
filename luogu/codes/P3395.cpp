/*************************************************************
 *  > File Name        : P3395.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/31 16:12:08
 *  > Algorithm        : [Search]BFS
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

int n, zx[maxn << 1], zy[maxn << 1];
int gox[4] = {0, 0, 1, -1}, goy[4] = {1, -1, 0, 0};
bool G[maxn][maxn], vis[maxn][maxn], flg;

struct Node {
    int x, y, t;
};

void bfs(int x, int y, int t) {
    queue<Node> q;
    q.push((Node){x, y, t});
    while (!q.empty()) {
        Node top = q.front(); q.pop();
        int tx = top.x, ty = top.y, tt = top.t;
        if (tx == n && ty == n) {
            flg = true;
            break;
        }
        G[zx[tt - 1]][zy[tt - 1]] = 1;
        for (int i = 0; i < 4; ++i) {
            int dx = tx + gox[i], dy = ty + goy[i];
            if (dx >= 1 && dx <= n && dy >= 1 && dy <= n && G[dx][dy] == 0 && vis[dx][dy] == 0) {
                vis[dx][dy] = 1;
                q.push((Node){dx, dy, tt + 1});
            }
        }
    }
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        memset(G  , 0, sizeof(G  ));
        memset(vis, 0, sizeof(vis));
        flg = false;
        for (int i = 1; i <= 2 * n - 2; ++i) {
            zx[i] = read(); zy[i] = read();
        }
        vis[1][1] = 1;
        bfs(1, 1, 0);
        printf(flg ? "Yes\n" : "No\n");
    }
    return 0;
}