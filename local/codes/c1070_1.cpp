/*************************************************************
 *  > File Name        : c1070_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/28 15:51:13
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

const int maxn = 1000010;

struct B {
    LL l, r;
}b[maxn];
bool cmp(B a, B b) {
    return a.r < b.r;
}
LL n, m, ans = 0;

LL bit[maxn];
void add(LL x, LL k) {
    for (; x <= maxn - 10; x += x & -x) bit[x] += k;
}
LL ask(LL x) {
    LL res = 0;
    for (; x; x -= x & -x) res += bit[x];
    return res;
}

int main() {
    n = read(); m = read();
    for (LL i = 1; i <= n; ++i) {
        b[i].l = i;
        b[i].r = read();
    }
    sort(b + 1, b + 1 + n, cmp);
    for (LL j = 1; j <= n; ++j) {
        b[j].r = b[j].l;
        b[j].l = j;
    }
    if (m % 2 == 0) {
        sort(b + 1, b + 1 + n, cmp);
        for (LL j = 1; j <= n; ++j) {
            b[j].r = b[j].l;
            b[j].l = j;
        }
    }
    for (LL i = n; i; --i) {
        ans += ask(b[i].r - 1);
        add(b[i].r, 1);
    }
    printf("%lld\n", ans);
    return 0;
}