/*************************************************************
 *  > File Name        : c1071_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/04 12:05:00
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

const int maxn = 200010;
const int inf  = 0x7fffffff;

int n, m, a[maxn];

struct Node {
    int laz;
    int sum, maxx, minn;
    #define sum(p) tree[p].sum
    #define laz(p) tree[p].laz
    #define maxx(p) tree[p].maxx
    #define minn(p) tree[p].minn
}tree[maxn << 2];

void pushup(int p) {
    sum(p) = sum(p<<1) + sum(p<<1|1);
    maxx(p) = max(maxx(p<<1), maxx(p<<1|1));
    minn(p) = min(minn(p<<1), minn(p<<1|1));
}

void build(int p, int l, int r) {
    if (l == r) {
        sum(p) = maxx(p) = minn(p) = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void pushdown(int p) {
    if (laz(p)) {
        sum(p<<1) = -sum(p<<1);
        sum(p<<1|1) = -sum(p<<1|1);
        int tmp = maxx(p<<1);
        maxx(p<<1) = -minn(p<<1);
        minn(p<<1) = -tmp;
        tmp = maxx(p<<1|1);
        maxx(p<<1|1) = -minn(p<<1|1);
        minn(p<<1|1) = -tmp;
        laz(p<<1) ^= 1;
        laz(p<<1|1) ^= 1;
        laz(p) = 0;
    }
}

void updPoint(int p, int L, int R, int id, int v) {
    if (L == R && L == id) {
        laz(p) = 0;
        sum(p) = maxx(p) = minn(p) = v;
        return;
    }
    pushdown(p);
    int mid = (L + R) >> 1;
    if (id <= mid) updPoint(p<<1, L, mid, id, v);
    if (id >  mid) updPoint(p<<1|1, mid + 1, R, id, v);
    pushup(p);
}

void updAdd(int p, int L, int R, int id, int v) {
    if (L == R && L == id) {
        laz(p) = 0;
        sum(p) += v;
        maxx(p) += v;
        minn(p) += v;
        return;
    }
    pushdown(p);
    int mid = (L + R) >> 1;
    if (id <= mid) updAdd(p<<1, L, mid, id, v);
    if (id >  mid) updAdd(p<<1|1, mid + 1, R, id, v);
    pushup(p);
}

void updRange(int p, int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        sum(p) = -sum(p);
        int tmp = maxx(p);
        maxx(p) = -minn(p);
        minn(p) = -tmp;
        laz(p) ^= 1;
        return;
    }
    pushdown(p);
    int mid = (L + R) >> 1;
    if (l <= mid) updRange(p<<1, L, mid, l, r);
    if (r >  mid) updRange(p<<1|1, mid + 1, R, l, r);
    pushup(p);
}

int queryMax(int p, int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        return maxx(p);
    }
    pushdown(p);
    int mid = (L + R) >> 1;
    int ans = -inf;
    if (l <= mid) ans = max(ans, queryMax(p<<1, L, mid, l, r));
    if (r >  mid) ans = max(ans, queryMax(p<<1|1, mid + 1, R, l, r));
    return ans;
}

int queryMin(int p, int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        return minn(p);
    }
    pushdown(p);
    int mid = (L + R) >> 1;
    int ans = inf;
    if (l <= mid) ans = min(ans, queryMin(p<<1, L, mid, l, r));
    if (r >  mid) ans = min(ans, queryMin(p<<1|1, mid + 1, R, l, r));
    return ans;
}

int querySum(int p, int L, int R, int l, int r) {
    if (l <= L && R <= r) {
        return sum(p);
    }
    pushdown(p);
    int mid = (L + R) >> 1;
    int ans = 0;
    if (l <= mid) ans += querySum(p<<1, L, mid, l, r);
    if (r >  mid) ans += querySum(p<<1|1, mid + 1, R, l, r);
    return ans;
}

int lastans = 0;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    build(1, 1, n);
    while (m--) {
        lastans = abs(lastans);
        int opt = read(), x = read(), y = read();
        int l = ((x ^ lastans) % n) + 1;
        int r = ((y ^ lastans) % n) + 1;
        if (l > r) swap(l, r);
        switch(opt) {
            case 1: updPoint(1, 1, n, ((x ^ lastans) % n) + 1, y); break;
            case 2: updAdd(1, 1, n, ((x ^ lastans) % n) + 1, y); break;
            case 3: updRange(1, 1, n, l, r); break;
            case 4: printf("%d\n", lastans = queryMax(1, 1, n, l, r)); break;
            case 5: printf("%d\n", lastans = queryMin(1, 1, n, l, r)); break;
            case 6: printf("%d\n", lastans = querySum(1, 1, n, l, r)); break;
        }
    }
    return 0;
}