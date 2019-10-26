/*************************************************************
 *  > File Name        : CF1251D.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 16:33:04
 *  > Algorithm        : 二分答案
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

const LL maxn = 200010;

struct Node {
    LL l, r;
}a[maxn];
bool cmp(Node a, Node b) {
    if (a.l != b.l) return a.l > b.l;
    return a.r > b.r;
}

LL n, m, half, ans;

bool check(LL x) {
    LL cnt = 0, tot = 0;
    for (LL i = 1; i <= n; ++i) {
        if (a[i].l >= x) {
            tot += a[i].l;
            cnt++;
        } else if (a[i].r < x) {
            tot += a[i].l;
        } else if (cnt < half) {
            cnt++;
            tot += x;
        } else {
            tot += a[i].l;
        }
    }
    if (cnt < half) return false;
    return tot <= m;
}

int main() {
    LL T = read();
    while (T--) {
        n = read(); m = read(); half = (n + 1) >> 1;
        for (LL i = 1; i <= n; ++i) {
            a[i].l = read(); a[i].r = read();
        }
        sort(a + 1, a + 1 + n, cmp);
        LL l = 0, r = 1e18;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}