/*************************************************************
 *  > File Name        : P6477.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/25 14:41:37
 *  > Algorithm        : SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;
const int mod  = 1e9 + 7;

int n, a[maxn], lst[maxn], b[maxn], pre[maxn];
long long res, ans;

struct SegmentTreeNode {
    int l, r;
    long long sum, add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
} tree[maxn << 2];

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
}
void pushdown(int p) {
    if (add(p)) {
        sum(p<<1) += add(p) * (r(p<<1) - l(p<<1) + 1); sum(p<<1) %= mod;
        sum(p<<1|1) += add(p) * (r(p<<1|1) - l(p<<1|1) + 1); sum(p<<1|1) %= mod;
        add(p<<1) += add(p);
        add(p<<1|1) += add(p);
        add(p) = 0;
    }
}
void update(int p, int l, int r, int d) {
    if (l <= l(p) && r >= r(p)) {
        sum(p) += (long long)d * (r(p) - l(p) + 1);
        add(p) += d;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, d);
    if (r >  mid) update(p<<1|1, l, r, d);
    sum(p) = sum(p<<1) + sum(p<<1|1);
    sum(p) %= mod;
}
long long query(int p, int l, int r) {
    if (l <= l(p) && r >= r(p)) return sum(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    long long ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i] = read();
    }
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - b - 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
    }
    for (int i = 1; i <= n; ++i) {
        if (pre[a[i]]) lst[i] = pre[a[i]];
        pre[a[i]] = i;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        res += 2 * query(1, lst[i] + 1, i - 1) + i - lst[i];
        res %= mod;
        update(1, lst[i] + 1, i, 1);
        ans += res; ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}