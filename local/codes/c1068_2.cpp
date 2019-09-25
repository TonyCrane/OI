/*************************************************************
 *  > File Name        : c1068_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/22 15:57:06
 *  > Algorithm        : 
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

const int maxn = 500010;

LL n, m, a[maxn], b[maxn], ans;

LL calc(LL p) {
    b[n] = min(a[n], (LL)m * p - (LL)p * (p - 1) / 2 * n);
    for (LL i = n - 1; i; --i) {
        b[i] = min(a[i], b[i + 1] - p);
    }
    if (b[1] < p + p * (p - 1) / 2 * n) return 0;
    LL sum = b[1], buy = b[1];
    LL s = max(1LL, b[1] - (m + 1) * (p - 1) + p * (p - 1) / 2 * n);
    LL free = m - (LL)n * p - s + 1;
    for (LL i = 2; i <= n; ++i) {
        buy += p;
        LL tmp = min(b[i] - buy, free);
        free -= tmp;
        buy += tmp;
        sum += buy;
    }
    return sum;
}

int main() {
    LL T = read();
    while (T--) {
        n = read(), m = read();
        for (LL i = 1; i <= n; ++i) {
            a[i] = read();
        }
        ans = 0;
        for (LL i = 1; i * n <= m; ++i) {
            ans = max(ans, calc(i));
        }
        printf("%lld\n", ans);
    }
    return 0;
}