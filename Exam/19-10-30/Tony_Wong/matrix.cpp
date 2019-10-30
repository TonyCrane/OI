/*************************************************************
 *  > File Name        : matrix.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/30 16:43:54
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 8010;

int n, m, q, lastans;
int t1[maxn][maxn];
int t2[maxn][maxn];
int t3[maxn][maxn];
int t4[maxn][maxn];

void add(int x, int y, int k) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            t1[i][j] += k;
            t2[i][j] += k * x;
            t3[i][j] += k * y;
            t4[i][j] += k * x * y;
        }
    }
}

int ask(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i) {
        for (int j = y; j; j -= j & -j) {
            res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        }
    }
    return res;
}

int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    n = read(); m = read(); q = read();
    while (m--) {
        int opt = read(), _x1 = read(), _x2 = read(), _y1 = read(), _y2 = read();
        _x1 = (_x1 + lastans) % n + 1;
        _x2 = (_x2 + lastans) % n + 1;
        _y1 = (_y1 + lastans) % n + 1;
        _y2 = (_y2 + lastans) % n + 1;
        if (_x2 < _x1) swap(_x2, _x1);
        if (_y2 < _y1) swap(_y2, _y1);
        if (opt == 1) {
            add(_x2 + 1, _y2 + 1, 1);
            add(_x1, _y2 + 1, -1);
            add(_x2 + 1, _y1, -1);
            add(_x1, _y1, 1);
        } else {
            int ans = ask(_x2, _y2) - ask(_x2, _y1 - 1) - ask(_x1 - 1, _y2) + ask(_x1 - 1, _y1 - 1);
            printf("%d\n", (ans + q) % q);
            lastans += ans % q;
        }
    }
    return 0;
}