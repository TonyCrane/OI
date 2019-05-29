/*************************************************************
 *  > File Name        : SP1716.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/29 16:28:31
 *  > Algorithm        : [DataStructure]SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define lt (p<<1)
#define rt (p<<1|1)

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

struct SegmentTree {
    int l, r;
    int sum, lmax, rmax, dat;
    #define l(x)    tree[x].l
    #define r(x)    tree[x].r
    #define sum(x)  tree[x].sum
    #define lmax(x) tree[x].lmax
    #define rmax(x) tree[x].rmax
    #define dat(x)  tree[x].dat
} tree[maxn * 4];

void update(int p) {
    sum(p)  = sum(lt) + sum(rt);
    lmax(p) = max(lmax(lt), sum(lt) + lmax(rt));
    rmax(p) = max(rmax(rt), sum(rt) + rmax(lt));
    dat(p)  = max(dat(lt), dat(rt));
    dat(p)  = max(dat(p), rmax(lt) + lmax(rt));
}

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if (l == r) {
        dat(p) = sum(p) = lmax(p) = rmax(p) = read();
        return;
    }
    int mid = (l + r) >> 1;
    build(lt, l, mid);
    build(rt, mid + 1, r);
    update(p);
}

void change(int p, int x, int k) {
    if (l(p) == x && r(p) == x) {
        dat(p) = lmax(p) = rmax(p) = sum(p) = k;
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    if (x > mid) change(rt, x, k);
    else change(lt, x, k);
    update(p);
}

SegmentTree query(int p, int l, int r) {
    if (l <= l(p) && r >= r(p)) return tree[p];
    int mid = (l(p) + r(p)) >> 1;
    if (l >  mid) return query(rt, l, r);
    if (r <= mid) return query(lt, l, r);
    else {
        SegmentTree ans, a, b;
        a = query(lt, l, r); b = query(rt, l, r);
        ans.sum  = a.sum + b.sum;
        ans.dat  = max(a.dat, b.dat);
        ans.dat  = max(ans.dat, a.rmax + b.lmax);
        ans.lmax = max(a.lmax, a.sum + b.lmax);
        ans.rmax = max(b.rmax, b.sum + a.rmax);
        return ans; 
    }
}

int main() {
    int n = read();
    build(1, 1, n);
    int m = read();
    for (int i = 1; i <= m; ++i) {
        int k = read(), x = read(), y = read();
        if (k == 0) change(1, x, y);
        else printf("%d\n", query(1, x, y).dat);
    }
    return 0;
}