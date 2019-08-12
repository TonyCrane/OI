/*************************************************************
 *  > File Name        : P4145.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/12 16:16:36
 *  > Algorithm        : [DataStructure]SegmentTree
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

int n, m;
long long a[maxn];

struct SegmentTreeNode {
    int l, r;
    long long dat, laz;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define dat(x) tree[x].dat
    #define laz(x) tree[x].laz
} tree[maxn << 2];

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if (l == r) { dat(p) = laz(p) = a[l]; return; }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    dat(p) = dat(p<<1) + dat(p<<1|1);
    laz(p) = max(laz(p<<1), laz(p<<1|1));
}

void update(int p, int l, int r) {
    if (l(p) == r(p)) {
        dat(p) = laz(p) = sqrt(dat(p));
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid && laz(p<<1) > 1) update(p<<1, l, r);
    if (r >  mid && laz(p<<1|1) > 1) update(p<<1|1, l, r);
    dat(p) = dat(p<<1) + dat(p<<1|1);
    laz(p) = max(laz(p<<1), laz(p<<1|1));
}

long long query(int p, int l, int r) {
    if (l <= l(p) && r >= r(p)) return dat(p);
    int mid = (l(p) + r(p)) >> 1;
    long long ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    build(1, 1, n);
    m = read();
    for (int i = 1; i <= m; ++i) {
        int k = read(), l = read(), r = read();
        if (l > r) swap(l, r);
        if (k == 0) update(1, l, r);
        else printf("%lld\n", query(1, l, r));
    }
    return 0;
}