/*************************************************************
 *  > File Name        : c1069_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/25 15:27:36
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

const int maxn = 50010;

int r, c, q, G[maxn][20];

struct SegmentTree {
    struct SegmentTreeNode {
        int l, r, len;
        int dat, laz, num; // laz -1 不变 0 改为0 1 改为1  num 1的个数
        #define l(p) tree[p].l
        #define r(p) tree[p].r
        #define len(p) tree[p].len
        #define dat(p) tree[p].dat
        #define laz(p) tree[p].laz
        #define num(p) tree[p].num
    }tree[maxn << 2];
    void pushup(int p) {
        dat(p) = dat(p<<1) + dat(p<<1|1);
        num(p) = num(p<<1) + num(p<<1|1);
    }
    void build(int p, int l, int r, int c) {
        l(p) = l; r(p) = r; len(p) = r - l + 1;
        if (l == r) {
            dat(p) = G[l][c] ^ 1;
            num(p) = G[l][c];
            return;
        }
        int mid = (l + r) >> 1;
        build(p<<1, l, mid, c);
        build(p<<1|1, mid + 1, r, c);
        pushup(p);
    }
    void pushdown(int p) {
        if (laz(p) == -1) return;
        if (laz(p) == 0) {
            dat(p<<1) = len(p<<1) - num(p<<1);
            dat(p<<1|1) = len(p<<1|1) - num(p<<1|1);
        } else if (laz(p) == 1) {
            dat(p<<1) = num(p<<1);
            dat(p<<1|1) = num(p<<1|1);
        }
        laz(p<<1) = laz(p<<1|1) = laz(p);
        laz(p) = -1;
    }
    void update(int p, int l, int r, int x) {
        if (l <= l(p) && r(p) <= r) {
            if (x == 1) dat(p) = num(p);
            else dat(p) = len(p) - num(p);
            laz(p) = x;
            return;
        }
        pushdown(p);
        int mid = (l(p) + r(p)) >> 1;
        if (l <= mid) update(p<<1, l, r, x);
        if (r >  mid) update(p<<1|1, l, r, x);
        pushup(p);
    }
    int query() {
        return dat(1);
    }
}Tree[16];

int main() {
    r = read(); c = read(); q = read();
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            char ch = getchar();
            while (ch != '0' && ch != '1') ch = getchar();
            G[i][j] = ch - '0';
        }
    }
    for (int i = 1; i <= c; ++i) {
        Tree[i].build(1, 1, r, i);
    }
    for (int i = 1; i <= q; ++i) {
        int r1 = read(), r2 = read();
        int c1 = read(), c2 = read();
        int x = read();
        for (int j = c1; j <= c2; ++j) {
            Tree[j].update(1, r1, r2, x);
        }
        int ans = 0;
        for (int j = 1; j <= c; ++j) {
            ans += Tree[j].query();
        }
        printf("%d\n", ans);
    }
    return 0;
}