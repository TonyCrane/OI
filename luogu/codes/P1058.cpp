/*************************************************************
 *  > File Name        : P1058.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/19 16:13:25
 *  > Algorithm        : [Simulation]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const char block[6][8] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};

int a[60][60];
char ans[1010][1010];

void add(int x, int y) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (block[5 - i][j] != '.') {
                ans[x - i][y + j] = block[5 - i][j];
            }
        }
    }
}

void init(int len, int wid) {
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= wid; ++j) {
            ans[i][j] = '.';
        }
    }
}

int main() {
    int n = read(), m = read(), len = 0, wid;
    wid = 4 * m + 2 * n + 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = read();
            len = max(len, a[i][j] * 3 + 2 * n - 2 * i + 3);
        }
    }
    init(len, wid);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = len - 2 * (n - i);
            int y = 2 * (n - i) + 4 * (j - 1) + 1;
            while (a[i][j]--) {
                add(x, y);
                x -= 3;
            }
        }
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= wid; ++j) {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}