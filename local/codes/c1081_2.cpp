/*************************************************************
 *  > File Name        : c1081_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/31 12:35:23
 *  > Algorithm        : BIT
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
unsigned char t1[maxn][maxn];
unsigned char t2[maxn][maxn];
unsigned char t3[maxn][maxn];
unsigned char t4[maxn][maxn];

void add(int x, int y, int k) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= n; j += j & -j) {
            t1[i][j] = (k+(long long)t1[i][j]+(long long)q*124320) % q;
            t2[i][j] = (k * x+(long long)t2[i][j]+(long long)q*122320) % q;
            t3[i][j] = (k * y+(long long)t3[i][j]+(long long)q*144220) % q;
            t4[i][j] = (k * x * y+(long long)t4[i][j]+(long long)q*2562600) % q;
        }
    }
}

int ask(int x, int y) {
    long long res = 0;
    for (int i = x; i; i -= i & -i) {
        for (int j = y; j; j -= j & -j) {
            res += ((long long)(x + 1) % q * (long long)(y + 1) % q * (long long)t1[i][j] % q) % q \
                 + (long long)q*123842 - ((long long)(y + 1) % q * (long long)t2[i][j] % q) % q + (long long)q*124556 - ((long long)(x + 1) % q * (long long)t3[i][j] % q) % q + (long long)t4[i][j] % q;
            res += (long long)q*123452; res %= q;
        }
    }
    return res;
}

int main() {
    // freopen("matrix.in", "r", stdin);
    // freopen("matrix.out", "w", stdout);
    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));
    memset(t3,0,sizeof(t3));
    memset(t4,0,sizeof(t4));
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
            int ans = (((ask(_x2, _y2) % q + ask(_x1 - 1, _y1 - 1) % q) + (long long)q*120938 - ask(_x2, _y1 - 1)) % q + (long long)q*128433 - ask(_x1 - 1, _y2)) % q;
            printf("%d\n", ans % q);
            lastans += ans % q;
            lastans%=n;
        }
    }
    return 0;
}