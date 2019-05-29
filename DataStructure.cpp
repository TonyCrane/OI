/*************************************************************
 *  > Description      : 数据结构模板
 *  > File Name        : DataStructure.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/29 12:11:37
 *  > Copyright (C) 2019 Tony
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

/**
 * @brief 树状数组
 */
int bit[maxn], n, m;
int lowbit(int k) { return k & -k; }
void add(int x, int k) {
    while (x <= n) {
        bit[x] += k;
        x += lowbit(x);
    }
}
int sum(int x) {
    int ans = 0;
    while (x != 0) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

/**
 * @brief 线段树
 */
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