/*************************************************************
 *  > File Name        : P4011.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/22 07:51:05
 *  > Algorithm        : 状压 01BFS
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 20;
const int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m, p, k;
int cnt[maxn][maxn], key[maxn][maxn][maxn];
bool vis[maxn][maxn][1 << 15];
int edge[maxn][maxn][maxn][maxn];

struct Node {
    int x, y;
    int keys, times;
    Node(int x, int y, int k, int t): x(x), y(y), keys(k), times(t) {}
};

queue<Node> q;
int bfs() {
    int skey = 0;
    for (int i = 1; i <= cnt[1][1]; ++i) skey |= (1 << (key[1][1][i] - 1));
    q.push(Node(1, 1, skey, 0)); vis[1][1][skey] = true;
    while (!q.empty()) {
        Node u = q.front(); q.pop();
        if (u.x == n && u.y == m) return u.times;
        for (int k = 0; k < 4; ++k) {
            int vx = u.x + go[k][0], vy = u.y + go[k][1];
            if (vx < 1 || vx > n || vy < 1 || vy > m) continue;
            int e = edge[u.x][u.y][vx][vy];
            if (e < 0 || (e > 0 && !(1 << (e - 1) & u.keys))) continue;
            int vkeys = 0;
            for (int i = 1; i <= cnt[vx][vy]; ++i) vkeys |= (1 << (key[vx][vy][i] - 1));
            int nxtkeys = u.keys | vkeys;
            if (vis[vx][vy][nxtkeys]) continue;
            q.push(Node(vx, vy, nxtkeys, u.times + 1));
            vis[vx][vy][nxtkeys] = true;
        }
    }
    return -1;
}


int main() {
    n = read(); m = read(); p = read(); k = read();
    for (int i = 1; i <= k; ++i) {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        int g = read();
        edge[x1][y1][x2][y2] = ((g == 0) ? -1 : g);
        edge[x2][y2][x1][y1] = edge[x1][y1][x2][y2];
    }
    int s = read();
    for (int i = 1; i <= s; ++i) {
        int x1 = read(), y1 = read(), q = read();
        key[x1][y1][++cnt[x1][y1]] = q;
    }
    int ans = bfs();
    printf("%d\n", ans);
    return 0;
}