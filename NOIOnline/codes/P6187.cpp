/*************************************************************
 *  > File Name        : P6187.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/24 22:36:14
 *  > Algorithm        : greedy
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

int n, m;
LL a[maxn], vis[maxn], ans;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n);
    for (int _ = 1; _ <= m; ++_) {
        int k = read(); ans = 0;
        int num = gcd(n, k);
        int per = n / num;
        if (k == 0) {
            for (int i = 1; i <= n; ++i) ans += a[i] * a[i];
            printf("%lld\n", ans);
            continue;
        }
        if (vis[num]) {
            printf("%lld\n", vis[num]);
            continue;
        }
        for (int i = 1; i <= n; i += per) {
            for (int j = 0; j < per - 2; ++j) {
                ans += a[i + j] * a[i + j + 2];
            }
            ans += a[i] * a[i + 1];
            ans += a[i + per - 2] * a[i + per - 1];
        }
        printf("%lld\n", vis[num] = ans);
    }
    return 0;
}