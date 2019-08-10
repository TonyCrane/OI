/*************************************************************
 *  > File Name        : P2894.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/10 15:36:31
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

const int maxn = 50010;

struct SegmentTree {
    struct SegmentTreeNode {
        int l, r;
        int sum, lmax, rmax, laz, len;
        // laz=1 退 laz=2 开
        #define l(x) tree[x].l
        #define r(x) tree[x].r
        #define sum(x) tree[x].sum
        #define lmax(x) tree[x].lmax
        #define rmax(x) tree[x].rmax
        #define laz(x) tree[x].laz
        #define len(x) tree[x].len
    } tree[maxn * 4];
    int n, m;
    void pushup(int p) {
        lmax(p) = (lmax(p<<1) == len(p<<1)) ? len(p<<1) + lmax(p<<1|1) : lmax(p<<1);
        rmax(p) = (rmax(p<<1|1) == len(p<<1|1)) ? len(p<<1|1) + rmax(p<<1) : rmax(p<<1|1);
        sum(p) = max(rmax(p<<1) + lmax(p<<1|1), max(sum(p<<1), sum(p<<1|1)));
    }
    void build(int p, int l, int r) {
        l(p) = l, r(p) = r;
        sum(p) = lmax(p) = rmax(p) = len(p) = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(p<<1, l, mid);
        build(p<<1|1, mid + 1, r);
    }
    void pushdown(int p) {
        if (!laz(p)) return;
        laz(p<<1) = laz(p<<1|1) = laz(p);
        sum(p<<1) = lmax(p<<1) = rmax(p<<1) = (laz(p) == 1) ? len(p<<1) : 0;
        sum(p<<1|1) = lmax(p<<1|1) = rmax(p<<1|1) = (laz(p) == 1) ? len(p<<1|1) : 0;
        laz(p) = 0;
    }
    void update(int p, int l, int r, int tag) {
        if (l <= l(p) && r(p) <= r) {
            sum(p) = lmax(p) = rmax(p) = (tag == 1) ? len(p) : 0;
            laz(p) = tag;
            return;
        }
        pushdown(p);
        int mid = (l(p) + r(p)) >> 1;
        if (l <= mid) update(p<<1, l, r, tag);
        if (r >  mid) update(p<<1|1, l, r, tag);
        pushup(p);
    }
    int query(int p, int len) {
        if(l(p) == r(p)) return l(p);
        pushdown(p);
        if (sum(p<<1) >= len) return query(p<<1, len);
        int mid = (l(p) + r(p)) >> 1;
        if (rmax(p<<1) + lmax(p<<1|1) >= len) return mid - rmax(p<<1) + 1;
        return query(p<<1|1, len); 
    }
    #undef lmax
    #undef rmax
    #undef len
    #undef laz
    #undef sum
    #undef l
    #undef r
}st;

int main() {
    st.n = read(); st.m = read();
    st.build(1, 1, st.n);
    while (st.m--) {
        int opt = read();
        if (opt == 1) {
            int x = read();
            if (st.tree[1].sum >= x) {
                int l = st.query(1, x);
                printf("%d\n", l);
                st.update(1, l, l + x - 1, 2);
            } else printf("0\n");
        } else {
            int x = read(), y = read();
            st.update(1, x, x + y - 1, 1);
        }
    }
    return 0;
}