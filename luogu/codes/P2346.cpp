/*************************************************************
 *  > File Name        : P2346.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/24 17:17:53
 *  > Algorithm        : ID-dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[6][6], ans;
int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool check() {
    for (int i = 1; i <= 4; ++i) {
        if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][3] == a[i][4]) return true;
        if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[3][i] == a[4][i]) return true;
    }
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[3][3] == a[4][4]) return true;
    if (a[1][4] == a[2][3] && a[2][3] == a[3][2] && a[3][2] == a[4][1]) return true;
    return false;
}

bool valid(int x, int y, int color) {
    return x > 0 && x <= 4 && y > 0 && y <= 4 && a[x][y] != color;
}

bool dfs(int x_, int y_, int x__, int y__, int color, int dep) {
    if (ans == dep) {
        if (check()) return true;
        return false;
    }
    for (int i = 0; i <= 3; ++i) {
        int nx_  = x_  + go[i][0];
        int ny_  = y_  + go[i][1];
        int nx__ = x__ + go[i][0];
        int ny__ = y__ + go[i][1];
        if (valid(nx_, ny_, color)) {
            swap(a[x_][y_], a[nx_][ny_]);
            if (dfs(nx_, ny_, x__, y__, color ^ 1, dep + 1)) return true;
            swap(a[x_][y_], a[nx_][ny_]);
        }
        if (valid(nx__, ny__, color)) {
            swap(a[x__][y__], a[nx__][ny__]);
            if (dfs(x_, y_, nx__, ny__, color ^ 1, dep + 1)) return true;
            swap(a[x__][y__], a[nx__][ny__]);
        }
    }
    return false;
}

int main() {
    char ch; int x_ = 0, y_ = 0, x__ = 0, y__ = 0;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> ch;
            if (ch == 'B') a[i][j] = 0;
            if (ch == 'W') a[i][j] = 1;
            if (ch == 'O') {
                a[i][j] = -1;
                if (!x_) { x_ = i; y_ = j; }
                else { x__ = i; y__ = j; }
            }
        }
    }
    for (ans = 1; ans <= 0x3f3f3f; ++ans) { // ID-dfs
        if (dfs(x_, y_, x__, y__, 0, 0)) break;
        if (dfs(x_, y_, x__, y__, 1, 0)) break;
    }
    printf("%d\n", ans);
    return 0;
}