/*************************************************************
 *  > File Name        : c1000_8.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/15 12:36:23
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

const int maxn = 20;

int r, c, ans;
char _map[maxn][maxn];

void dfs(int x, int y) {
    if (x == r - 1 && y == c - 1) {
        ans++;
        return;
    }
    for (int i = x + 1; i < r; ++i) {
        for (int j = y + 1; j < c; ++j) {
            if (_map[i][j] != _map[x][y]) {
                dfs(i, j);
            }
        }
    }
}

int main() {
    r = read(); c = read();
    for (int i = 0; i < r; ++i) {
        scanf("%s", _map[i]);
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}