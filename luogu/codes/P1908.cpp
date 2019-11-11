/*************************************************************
 *  > File Name        : P1908.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 21:26:57
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

const LL maxn = 500010;

LL n, a[maxn], t[maxn], ans, old[maxn];
void add(LL x, LL k) { for (; x <= n; x += x & -x) t[x] += k; }
LL ask(LL x) { LL res = 0; for (; x; x -= x & -x) res += t[x]; return res; }

int main() {
    n = read();
    for (LL i = 1; i <= n; ++i) {
        a[i] = read(); old[i] = a[i];
    }
    sort(old + 1, old + 1 + n);
    LL len = unique(old + 1, old + 1 + n) - old - 1;
    for (LL i = 1; i <= n; ++i) a[i] = lower_bound(old + 1, old + 1 + len, a[i]) - old;
    for (LL i = n; i; --i) {
        ans += ask(a[i] - 1);
        add(a[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}