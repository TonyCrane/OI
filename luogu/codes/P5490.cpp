/*************************************************************
 *  > File Name        : P5490.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/12 16:07:32
 *  > Algorithm        : [DataStructure]SegmentTree
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

const LL maxn = 2100000;

struct SegmentTreeNode {
    LL l, r;
    LL len, cnt;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define len(x) tree[x].len
    #define cnt(x) tree[x].cnt
} tree[maxn];

struct Node {
    LL x, yh, yl, flag;
} edges[maxn];

bool cmp(Node a, Node b) {
    if (a.x != b.x) return a.x < b.x;
    return a.flag > b.flag;
}

LL n, rnk[maxn], val[maxn], cnt, maxx = 1 << 31;

void pushup(LL p) {
    if (l(p) == maxx && r(p) == maxx) return;
    if (cnt(p)) {
        len(p) = val[r(p) + 1] - val[l(p)];
    } else {
        len(p) = len(p<<1) + len(p<<1|1);
    }
}

void build(LL p, LL l, LL r) {
    l(p) = l, r(p) = r;
    if(l == r) return;
    LL mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
}

void update(LL p, LL l, LL r, LL v) {
    if (l <= l(p) && r(p) <= r) {
        cnt(p) += v;
        pushup(p);
        return;
    }
    LL mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, v);
    if (r >  mid) update(p<<1|1, l, r, v);
    pushup(p);
}

int main() {
    n = read(); LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x1_ = read(), y1_ = read(), x2_ = read(), y2_ = read();
        edges[(i << 1) - 1].x = x1_;
        edges[i << 1].x = x2_;
        edges[(i << 1) - 1].yh = y2_;
        edges[i << 1].yh = y2_;
        edges[(i << 1) - 1].yl = y1_;
        edges[i << 1].yl = y1_;
        edges[(i << 1) - 1].flag = 1;
        edges[i << 1].flag = -1;
        rnk[++cnt] = y1_;
        rnk[++cnt] = y2_;
    }
    sort(rnk + 1, rnk + 1 + (n << 1));
    cnt = unique(rnk + 1, rnk + 1 + (n << 1)) - rnk - 1;
    for (int i = 1; i <= 2 * n; ++i) {
        LL pos1 = lower_bound(rnk + 1, rnk + 1 + cnt, edges[i].yh) - rnk;
        LL pos2 = lower_bound(rnk + 1, rnk + 1 + cnt, edges[i].yl) - rnk;
        val[pos1] = edges[i].yh;
        val[pos2] = edges[i].yl;
        edges[i].yh = pos1;
        edges[i].yl = pos2;
        maxx = max(maxx, pos1);
    }
    sort(edges + 1, edges + 1 + 2 * n, cmp);
    build(1, 1, n << 1);
    for (int i = 1; i <= n << 1; ++i) {
        update(1, edges[i].yl, edges[i].yh - 1, edges[i].flag);
        ans += len(1) * (edges[i + 1].x - edges[i].x);
    }
    printf("%lld\n", ans);
    return 0;
}