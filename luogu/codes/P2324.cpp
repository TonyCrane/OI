/*************************************************************
 *  > File Name        : P2324.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/25 20:37:04
 *  > Algorithm        : IDA*
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int go[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
const int goal[7][7] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1},
    {0, 0, 0,-1, 1, 1},
    {0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0}
};

bool fini;
int T, n, m, sx, sy;
int _map[10][10];

inline bool valid(int x, int y) {
    return x >= 1 && x <= 5 && y >= 1 && y <= 5;
}

inline int f() {
    int res = 0;
    for (int i = 1; i <= 5; ++i) {
        for (int j = 1; j <= 5; ++j) {
            if (_map[i][j] != goal[i][j]) {
                res++;
            }
        }
    }
    return res;
}

void dfs(int x, int y, int dep, int maxd) {
    if (dep == maxd) {
        if (!f()) fini = true;
        return;
    }
    for (int i = 0; i < 8; ++i) {
        int nx = x + go[i][0];
        int ny = y + go[i][1];
        if (valid(nx, ny)) {
            swap(_map[x][y], _map[nx][ny]);
            if (f() + dep <= maxd) {
                dfs(nx, ny, dep + 1, maxd);
            }
            swap(_map[x][y], _map[nx][ny]);
        }
    }
}

int main() {
    T = read(); char ch;
    while (T--) {
        fini = false;
        for (int i = 1; i <= 5; ++i) {
            for (int j = 1; j <= 5; ++j) {
                cin >> ch;
                if (ch == '*') {
                    _map[i][j] = -1;
                    sx = i; sy = j;
                } else {
                    _map[i][j] = ch - '0';
                }
            }
        }
        if (!f()) {
            printf("-1\n");
            continue;
        }
        for (int dep = 1; dep <= 15; ++dep) {
            dfs(sx, sy, 0, dep);
            if (fini) {
                printf("%d\n", dep);
                goto Label;
            }
        }
        printf("-1\n");
        Label:;
    }
    return 0;
}