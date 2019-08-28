/*************************************************************
 *  > File Name        : P1007.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/28 15:22:35
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

int l, n, pos, minn, maxx;

int main() {
    l = read(); n = read();
    for (int i = 1; i <= n; ++i) {
        pos = read();
        maxx = max(maxx, max(l - pos + 1, pos));
        minn = max(minn, min(l - pos + 1, pos));
    }
    printf("%d %d\n", minn, maxx);
    return 0;
}