/*************************************************************
 *  > File Name        : c1066_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/17 13:01:17
 *  > Algorithm        : math
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL n, m, ans;

int main() {
    n = read() + 1; m = read() + 1;
    ans = (n * m) * (n * m - 1) * (n * m - 2) / 6;
    if (n >= 3) ans -= n * (n - 1) * (n - 2) / 6 * m;
    if (m >= 3) ans -= m * (m - 1) * (m - 2) / 6 * n;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            ans -= (n - i) * (m - j) * (gcd(i, j) - 1) * 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}