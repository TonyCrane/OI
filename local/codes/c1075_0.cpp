/*************************************************************
 *  > File Name        : c1075_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/15 12:26:41
 *  > Algorithm        : math
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

int n, m, a, res, ans;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    n = read(); res = read();
    for (int i = 2; i <= n; ++i) {
        a = read();
        res = gcd(res, a);
    }
    m = read();
    for (int i = 1; i <= m; ++i) {
        int x = read();
        if (x % res == 0) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}