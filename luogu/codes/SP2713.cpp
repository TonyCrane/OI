/*************************************************************
 *  > File Name        : SP2713.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/30 12:38:36
 *  > Algorithm        : [DataStructure]SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;
#define lt p<<1
#define rt p<<1|1

struct SegmentTree {
    int l, r;
    LL dat, tag;
    #define l(x)   tree[x].l
    #define r(x)   tree[x].r
    #define dat(x) tree[x].dat
    #define tag(x) tree[x].tag
} tree[maxn * 4];
LL a[maxn];

void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        dat(p) = tag(p) = a[l];
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    build(lt, l, mid);
    build(rt, mid + 1, r);
    dat(p) = dat(lt) + dat(rt);
    tag(p) = max(tag(lt), tag(rt));
}

void update(int p, int l, int r) {
    if (l(p) == r(p)) {
        dat(p) = sqrt(dat(p));
        tag(p) = dat(p);
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid && tag(lt) > 1) update(lt, l, r);
    if (r >  mid && tag(rt) > 1) update(rt, l, r);
    dat(p) = dat(lt) + dat(rt);
    tag(p) = max(tag(lt), tag(rt));
}

LL query(int p, int l, int r) {
    if (l <= l(p) && r >= r(p)) return dat(p);
    LL ans = 0;
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) ans += query(lt, l, r);
    if (r >  mid) ans += query(rt, l, r);
    return ans;
}

int n, m, kase;

int main() {
    while (~scanf("%d", &n)) {
        printf("Case #%d:\n", ++kase);
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        build(1, 1, n); m = read();
        while (m--) {
            int opt = read(), x = read(), y = read();
            if (x > y) swap(x, y);
            if (!opt) update(1, x, y);
            else printf("%lld\n", query(1, x, y));
        }
        printf("\n");
    }
    return 0;
}