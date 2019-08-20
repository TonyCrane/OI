/*************************************************************
 *  > File Name        : c1062_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/20 12:39:01
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

const int maxn = 10;

int n, in[maxn][maxn];
int G[maxn][maxn], ans[maxn][maxn]; // 1 / 2 \

bool check(int x, int y, int i) {
    if (i == 1) {
        if (in[x][y] != -1 && G[x][y] != in[x][y]) return false;
        if (in[x][y + 1] != -1 && G[x][y + 1] + 1 > in[x][y + 1]) return false;
        if (in[x + 1][y] != -1 && G[x + 1][y] + 1 > in[x + 1][y]) return false;
    } else if (i == 2) {
        if (in[x][y] != -1 && G[x][y] + 1 != in[x][y]) return false;
        if (in[x + 1][y + 1] != -1 && G[x + 1][y + 1] + 1 > in[x + 1][y + 1]) return false;
    }
    return true;
}

void dfs(int x, int y) {
    if (x == n && y == n) return;
    for (int i = 1; i <= 2; ++i) {
        if (check(x, y, i)) {
            ans[x][y] = i;
            if (i == 1) {
                G[x][y + 1]++;
                G[x + 1][y]++;
            } else {
                G[x][y]++;
                G[x + 1][y + 1]++;
            }
            if (y == n) {
                dfs(x + 1, 1);
            } else {
                dfs(x, y + 1);
            }
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n + 1; ++i) {
        char ch[maxn];
        scanf("%s", ch + 1);
        for (int j = 1; j <= n + 1; ++j) {
            if (ch[j] == '.') {
                in[i][j] = -1;
            } else {
                in[i][j] = ch[j] - 48;
            }
        }
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ans[i][j] == 1) {
                printf("/");
            } else {
                printf("\\");
            }
        }
        printf("\n");
    }
    return 0;
}