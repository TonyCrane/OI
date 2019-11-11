/*************************************************************
 *  > File Name        : P3372_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 08:18:59
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

int n, m, a[maxn];

struct Node {
    int l, r;
    LL dat, laz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) (tree[p].r - tree[p].l + 1)
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];

void pushup(int p) {
    dat(p) = dat(p<<1) + dat(p<<1|1);
}

void pushdown(int p) {
    if (laz(p)) {
        laz(p<<1) += laz(p); laz(p<<1|1) += laz(p);
        dat(p<<1) += len(p<<1) * laz(p);
        dat(p<<1|1) += len(p<<1|1) * laz(p);
        laz(p) = 0;
    }
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        dat(p) = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, int k) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) += k * len(p);
        laz(p) += k;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}

LL query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return dat(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1; LL ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int opt = read(), x = read(), y = read();
        if (opt == 1) {
            int k = read();
            update(1, x, y, k);
        } else {
            printf("%lld\n", query(1, x, y));
        }
    }
    return 0;
}