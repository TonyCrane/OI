/*************************************************************
 *  > File Name        : 1126.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/08 12:37:30
 *  > Algorithm        : 暴力
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int z, n, ans[110][110];
char _map[60][60];
bool vis[60][60];

bool check(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= n) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", _map[i] + 1);
    }
    for (int i = -n + 1; i < n; ++i) {
        for (int j = -n + 1; j < n; ++j) {
            int now = 0;
            for (int r = 1; r <= n; ++r) {
                for (int c = 1; c <= n; ++c) {
                    if (_map[r][c] == 'o') {
                        int tx = r + i, ty = c + j;
                        if (check(tx, ty)) {
                            if (_map[tx][ty] == '.') {
                                if (!now) {
                                    now = -1;
                                }
                            }
                        }
                    }
                }
            }
            ans[i + n][j + n] = now;
            if (now != -1) {
                for (int r = 1; r <= n; ++r) {
                    for (int c = 1; c <= n; ++c) {
                        if (_map[r][c] == 'o') {
                            int tx = r + i, ty = c + j;
                            if (check(tx, ty)) {
                                vis[tx][ty] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (_map[i][j] == 'x' && !vis[i][j]) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i < 2 * n; ++i) {
        for (int j = 1; j < 2 * n; ++j) {
            if (i == n && j == n) {
                printf("o");
                continue;
            }
            if (ans[i][j] < 0) {
                printf(".");
            } else {
                printf("x");
            }
        }
        printf("\n");
    }
    return 0;
}