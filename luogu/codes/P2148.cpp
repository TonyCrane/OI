/*************************************************************
 *  > File Name        : P2148.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/02 20:15:54
 *  > Algorithm        : 博弈SG
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int SG(int x, int y) {
    int tmp = (x - 1) | (y - 1), res = 0;
    while (tmp & 1) {
        res++;
        tmp >>= 1;
    }
    return res;
}

int main() {
    int T = read();
    while (T--) {
        int n = read() / 2, sg = 0;
        for (int i = 1; i <= n; ++i) {
            int x = read(), y = read();
            sg ^= SG(x, y);
        }
        printf(sg ? "YES\n" : "NO\n");
    }
    return 0;
}