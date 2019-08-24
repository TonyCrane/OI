/*************************************************************
 *  > File Name        : P4573.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/23 13:01:53
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;

bool row[maxn][maxn], col[maxn][maxn], block[maxn][maxn];
bool cmp[maxn][maxn][maxn][maxn];
int ans[maxn][maxn];

bool check(int x, int y, int i) {
    return !row[x][i] && !col[y][i] && !block[((x - 1) / 3) * 3 + (y - 1) / 3 + 1][i] \
        && (((ans[x - 1][y] > i) == cmp[x - 1][y][x][y]) || (x % 3 == 1)) \
        && (((ans[x][y - 1] > i) == cmp[x][y - 1][x][y]) || (y % 3 == 1));
}

void dfs(int x, int y) {
    if (ans[x][y]) {
        if (x == 9 && y == 9) {
            for (int i = 1; i <= 9; ++i) {
                for (int j = 1; j <= 9; ++j) {
                    printf("%d ", ans[i][j]);
                }
                printf("\n");
            }
            return;
        } else if (y == 9) {
            dfs(x + 1, 1);
        } else dfs(x, y + 1);
    } else {
        for (int i = 1; i <= 9; ++i) {
            if (check(x, y, i)) {
                ans[x][y] = i;
                row[x][i] = true; col[y][i] = true;
                block[((x - 1) / 3) * 3 + (y - 1) / 3 + 1][i] = true;
                dfs(x, y);
                ans[x][y] = 0;
                row[x][i] = false; col[y][i] = false;
                block[((x - 1) / 3) * 3 + (y - 1) / 3 + 1][i] = false;
            }
        }
    }
}

int main() {
    char ch;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 5; ++j) {
            if (j % 2 == 0) {
                for (int k = 1; k <= 9; ++k) {
                    cin >> ch;
                    if (ch == 'v') {
                        int a = (i - 1) * 3 + j / 2;
                        cmp[a][k][a + 1][k] = true;
                    }
                }
            } else {
                for (int k = 1; k <= 6; ++k) {
                    cin >> ch;
                    if (ch == '>') {
                        int a = (i - 1) * 3 + (j - 1) / 2 + 1;
                        int b = (k - 1) / 2 * 3 + (k - 1) % 2 + 1;
                        cmp[a][b][a][b + 1] = true;
                    }
                }
            }
        }
    }
    dfs(1, 1);
    return 0;
}