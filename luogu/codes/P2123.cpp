/*************************************************************
 *  > File Name        : P2123.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/13 15:31:22
 *  > Algorithm        : [Greedy]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 20010;

struct Node {
    int x, y, d;
    bool operator < (Node a) const {
        if (d != a.d) return d < a.d;
        if (d <= 0)   return x < a.x;
        return y > a.y;
    }
} a[maxn];

long long c[maxn];

int main() {
    int T = read();
    while (T--) {
        int n = read();
        for (int i = 1; i <= n; ++i) {
            a[i].x = read(); a[i].y = read();
            if (a[i].x > a[i].y) a[i].d = 1;
            else if (a[i].x < a[i].y) a[i].d = -1;
            else a[i].d = 0;
        }
        sort(a + 1, a + 1 + n);
        long long s = 0;
        for (int i = 1; i <= n; ++i) {
            s += a[i].x;
            c[i] = max(c[i - 1], s) + a[i].y;
        }
        printf("%lld\n", c[n]);
    }
    return 0;
}