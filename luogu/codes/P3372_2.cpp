/*************************************************************
 *  > File Name        : P3372_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/29 15:08:58
 *  > Algorithm        : [DataStructure]SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

struct SegmentTree {
    int l, r;
    long long sum, add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
} tree[maxn * 4];
int a[maxn], n, m;

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if (l == r) { sum(p) = a[l]; return; }
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}

void pushdown(int p) {
    if (add(p)) {
        sum(p * 2) += add(p) * (r(p * 2) - l(p * 2) + 1);
        sum(p * 2 + 1) += add(p) * (r(p * 2 + 1) - l(p * 2 + 1) + 1);
        add(p * 2) += add(p);
        add(p * 2 + 1) += add(p);
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
    if (l <= mid) update(p * 2, l, r, d);
    if (r >  mid) update(p * 2 + 1, l, r, d);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}

long long query(int p, int l, int r) {
    if (l <= l(p) && r >= r(p)) return sum(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    long long ans = 0;
    if (l <= mid) ans += query(p * 2, l, r);
    if (r >  mid) ans += query(p * 2 + 1, l, r);
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--) {
        int opt, x, y, k;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1) {
            scanf("%d", &k);
            update(1, x, y, k);
        } else {
            printf("%lld\n", query(1, x, y));
        }
    }
    return 0;
}