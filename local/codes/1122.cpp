/*************************************************************
 *  > File Name        : 1122.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/07 12:15:20
 *  > Algorithm        : 模拟
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

int n;
bool G[maxn][maxn];

bool check(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n && G[x][y];
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '#') G[i][j] = true;
        }
    }
    bool ans = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (G[i][j]) {
                if (check(i + 1, j) && check(i + 1, j - 1) && check(i + 1, j + 1) && check(i + 2, j)) {
                    G[  i  ][  j  ] = false;
                    G[i + 1][  j  ] = false;
                    G[i + 1][j - 1] = false;
                    G[i + 1][j + 1] = false;
                    G[i + 2][  j  ] = false;
                } else {
                    ans = false;
                    break;
                }
            }
        }
        if (!ans) {
            break;
        }
    }
    printf(ans ? "YES\n" : "NO\n");
    return 0;
}

/*
    .#.            i,j
    ###  i+1,j-1  i+1,j  i+1,j+1
    .#.           i+2,j
 */