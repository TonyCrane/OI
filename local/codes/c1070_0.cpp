/*************************************************************
 *  > File Name        : c1070_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/28 14:52:57
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

int sx, sy, tx, ty, x, y;

int main() {
    sx = read(); sy = read();
    tx = read(); ty = read();
    x  = read(); y  = read();
    int dx = abs(sx - tx), dy = abs(sy - ty);
    if (dx % x != 0 && dy % y != 0) {
        puts("NO");
    } else {
        if ((dx / x) % 2 == 1 && (dy / y) % 2 == 1) {
            puts("YES");
        } else if ((dx / x) % 2 == 0 && (dy / y) % 2 == 0) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}