/*************************************************************
 *  > File Name        : P3865_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 08:05:08
 *  > Algorithm        : review ST
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

int a[maxn], f[maxn][30], n, m;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        f[i][0] = a[i];
    }
    for (int j = 1; j <= 20; ++j) {
        for (int i = 1; i <= n - (1 << j) + 1; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int l = read(), r = read();
        int k = log(r - l + 1) / log(2);
        printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
    }
    return 0;
}