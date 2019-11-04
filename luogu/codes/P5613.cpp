/*************************************************************
 *  > File Name        : P5613.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/04 12:38:31
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

const int maxn = 1010;

int n, m, k, p, ans, a[maxn], now;

int main() {
    n = read(); m = read(); k = read();
    for (int i = 1; i <= k; ++i) p = read(), a[p] = 1;
    while (now < n) {
        now += m;
        ans++;
        if (a[now]) m++;
    }
    printf("%d\n", ans);
    return 0;
}