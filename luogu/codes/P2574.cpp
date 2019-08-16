/*************************************************************
 *  > File Name        : P2574.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/16 15:53:10
 *  > Algorithm        : [DataStructure]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
inline int getint(){
    char ch = getchar();
    while (ch != '0' && ch != '1') ch = getchar();
    return ch - 48;
}

const int maxn = 200010;

int n, m;

struct Node {
    int l, r;
    int val, laz, len;
    #define val(p) tree[p].val
    #define laz(p) tree[p].laz
    #define len(p) tree[p].len
    #define l(p) tree[p].l
    #define r(p) tree[p].r
}tree[maxn << 2];

void build(int p, int l, int r) {
    l(p) = l; r(p) = r; len(p) = r - l + 1;
    if (l == r) { val(p) = getint(); return; }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    val(p) = val(p<<1) + val(p<<1|1);
}

void pushdown(int p) {
    laz(p<<1) ^= 1; laz(p<<1|1) ^= 1;
    val(p<<1) = len(p<<1) - val(p<<1);
    val(p<<1|1) = len(p<<1|1) - val(p<<1|1);
    laz(p) = 0;
}

void update(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) {
        val(p) = len(p) - val(p);
        laz(p) ^= 1;
        return;
    }
    if (laz(p)) pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r);
    if (r >  mid) update(p<<1|1, l, r);
    val(p) = val(p<<1) + val(p<<1|1);
}

int query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return val(p);
    if (laz(p)) pushdown(p);
    int ans = 0, mid = (l(p) + r(p)) >> 1;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

int main() {
    n = read(), m = read();
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int p = read(), l = read(), r = read();
        if (p == 0) {
            update(1, l, r);
        } else {
            printf("%d\n", query(1, l, r));
        }
    }
    return 0;
}