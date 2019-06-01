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
const int inf  = 0x3f3f3f3f;

/**
 * @brief 树状数组
 */
struct BIT {
    int bit[maxn], n, m;
    int lowbit(int k) { return k & -k; }
    void add(int x, int k) {
        while (x <= maxn) {
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
};

/**
 * @brief 线段树
 */
struct SegmentTree {
    struct SegmentTreeNode {
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
};

/**
 * @brief 二叉查找树
 */
struct BST {
    struct BSTNode {
        int l, r;
        int val;
    } a[maxn];
    int tot, root;
    int New(int val) {
        a[++tot].val = val;
        return tot;
    }
    void build() {
        New(-inf); New(inf);
        root = 1; a[1].r = 2;
    }
    int Get(int p, int val) {
        if (p == 0) return 0;
        if (val == a[p].val) return p;
        return val < a[p].val ? Get(a[p].l, val) : Get(a[p].r, val);
    }
    void insert(int& p, int val) {
        if (p == 0) {
            p = New(val);
            return;
        }
        if (val == a[p].val) return;
        if (val <  a[p].val) insert(a[p].l, val);
        else insert(a[p].r, val);
    }
    int getNext(int val) {
        int ans = 2, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].r > 0) {
                    p = a[p].r;
                    while (a[p].l > 0) p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val && a[p].val < a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return ans;
    }
    void remove(int val) {
        int& p = root;
        while (p) {
            if (val == a[p].val) break;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        if (p == 0) return;
        if (a[p].l == 0) p = a[p].r;
        else if (a[p].r == 0) p = a[p].l;
        else {
            int next = a[p].r;
            while (a[next].l > 0) next = a[next].l;
            remove(a[next].val);
            a[next].l = a[p].l;
            a[next].r = a[p].r;
            p = next;
        }
    }
};

/**
 * @brief 平衡树(Treap)
 */
struct Treap {
    struct TreapNode {
        int l, r;
        int val, dat;
        int cnt, size;
    } a[maxn];
    int tot, root, n;
    int New(int val) {
        a[++tot].val = val;
        a[tot].dat   = rand();
        a[tot].cnt   = 1;
        a[tot].size  = 1;
        return tot;
    }
    void update(int p) {
        a[p].size = a[a[p].l].size + a[a[p].r].size + a[p].cnt;
    }
    void build() {
        New(-inf); New(inf);
        root = 1;
        a[1].r = 2;
        update(root);
    }
    int GetRankByVal(int p, int val) {
        if (p == 0) return 0;
        if (val == a[p].val) return a[a[p].l].size + 1;
        if (val <  a[p].val) return GetRankByVal(a[p].l, val);
        return GetRankByVal(a[p].r, val) + a[a[p].l].size + a[p].cnt;
    }
    int GetValByRank(int p, int rank) {
        if (p == 0) return inf;
        if (a[a[p].l].size >= rank) return GetValByRank(a[p].l, rank);
        if (a[a[p].l].size + a[p].cnt >= rank) return a[p].val;
        return GetValByRank(a[p].r, rank - a[a[p].l].size - a[p].cnt);
    }
    void zig(int& p) {
        int q = a[p].l;
        a[p].l = a[q].r; a[q].r = p; p = q;
        update(a[p].r); update(p);
    }
    void zag(int& p) {
        int q = a[p].r;
        a[p].r = a[q].l; a[q].l = p; p = q;
        update(a[p].l); update(p);
    }
    void insert(int& p, int val) {
        if (p == 0) {
            p = New(val);
            return;
        }
        if (val == a[p].val) {
            a[p].cnt++; update(p);
            return;
        }
        if (val < a[p].val) {
            insert(a[p].l, val);
            if (a[p].dat < a[a[p].l].dat) zig(p);
        } else {
            insert(a[p].r, val);
            if (a[p].dat < a[a[p].r].dat) zag(p);
        }
        update(p);
    }
    int GetPre(int val) {
        int ans = 1, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].l > 0) {
                    p = a[p].l;
                    while (a[p].r > 0) p = a[p].r;
                    ans = p;
                }
                break;
            }
            if (a[p].val < val && a[p].val > a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
    int GetNext(int val) {
        int ans = 2, p = root;
        while (p) {
            if (val == a[p].val) {
                if (a[p].r > 0) {
                    p = a[p].r;
                    while (a[p].l > 0) p = a[p].l;
                    ans = p;
                }
                break;
            }
            if (a[p].val > val && a[p].val < a[ans].val) ans = p;
            p = val < a[p].val ? a[p].l : a[p].r;
        }
        return a[ans].val;
    }
    void Remove(int& p, int val) {
        if (p == 0) return;
        if (val == a[p].val) {
            if (a[p].cnt > 1) {
                a[p].cnt--; update(p);
                return;
            }
            if (a[p].l || a[p].r) {
                if (a[p].r == 0 || a[a[p].l].dat > a[a[p].r].dat) {
                    zig(p); Remove(a[p].r, val);
                } else {
                    zag(p); Remove(a[p].l, val);
                }
                update(p);
            } else p = 0;
            return;
        }
        val < a[p].val ? Remove(a[p].l, val) : Remove(a[p].r, val);
        update(p);
    }
};