/*************************************************************
 *  > File Name        : P4513.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/17 11:31:49
 *  > Algorithm        : [DataStructure]SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500010;

int n, m;

struct TreeNode {
    int l, r;
    int dat, sum, lmax, rmax;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define dat(p) tree[p].dat
    #define sum(p) tree[p].sum
    #define lmax(p) tree[p].lmax
    #define rmax(p) tree[p].rmax
} tree[maxn << 2];

void pushup(int p) {
    sum(p) = sum(p<<1) + sum(p<<1|1);
    lmax(p) = max(lmax(p<<1), sum(p<<1) + lmax(p<<1|1));
    rmax(p) = max(rmax(p<<1|1), sum(p<<1|1) + rmax(p<<1));
    dat(p) = max(dat(p<<1), dat(p<<1|1));
    dat(p) = max(dat(p), rmax(p<<1) + lmax(p<<1|1));
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) { dat(p) = sum(p) = lmax(p) = rmax(p) = read(); return; }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void change(int p, int x, int v) {
    if (l(p) == x && r(p) == x) { dat(p) = sum(p) = lmax(p) = rmax(p) = v; return; }
    int mid = (l(p) + r(p)) >> 1;
    if (x > mid) change(p<<1|1, x, v);
    else         change(p<<1, x, v);
    pushup(p);
}

TreeNode query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return tree[p];
    int mid = (l(p) + r(p)) >> 1;
    if (r <= mid) return query(p<<1, l, r);
    if (l >  mid) return query(p<<1|1, l, r);
    else {
        TreeNode ans, a = query(p<<1, l, r), b = query(p<<1|1, l, r);
        ans.sum = a.sum + b.sum;
        ans.dat = max(a.dat, b.dat);
        ans.dat = max(ans.dat, a.rmax + b.lmax);
        ans.lmax = max(a.lmax, a.sum + b.lmax);
        ans.rmax = max(b.rmax, b.sum + a.rmax);
        return ans;
    }
}

int main() {
    n = read(); m = read();
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int k = read(), a = read(), b = read();
        if (k == 1) {
            if (a > b) swap(a, b);
            printf("%d\n", query(1, a, b).dat);
        } else {
            change(1, a, b);
        }
    }
    return 0;
}