/*************************************************************
 *  > File Name        : P3373.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/15 12:20:18
 *  > Algorithm        : SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * (LL)f;
}

const int maxn = 100010;

int n, m, mod;

struct Node {
    int l, r, len;
    LL dat, add, mul;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) tree[p].len
    #define dat(p) tree[p].dat
    #define add(p) tree[p].add
    #define mul(p) tree[p].mul
}tree[maxn << 2];

void pushup(int p) {
    dat(p) = ( dat(p<<1) + dat(p<<1|1) ) % mod;
}

void pushdown(int p) {
    dat(p<<1) = ( dat(p<<1) * mul(p) + add(p) * len(p<<1) ) % mod;
    dat(p<<1|1) = ( dat(p<<1|1) * mul(p) + add(p) * len(p<<1|1) ) % mod;
    mul(p<<1) *= mul(p); mul(p<<1) %= mod;
    mul(p<<1|1) *= mul(p); mul(p<<1|1) %= mod;
    add(p<<1) = ( add(p<<1) * mul(p) + add(p) ) % mod;
    add(p<<1|1) = ( add(p<<1|1) * mul(p) + add(p) ) % mod;
    mul(p) = 1LL; add(p) = 0; 
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r; 
    mul(p) = 1LL; len(p) = r - l + 1;
    if (l == r) {
        dat(p) = read() % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p); 
}

void updmul(int p, int l, int r, LL k) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) *= k; dat(p) %= mod;
        mul(p) *= k; mul(p) %= mod;
        add(p) *= k; add(p) %= mod;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) updmul(p<<1, l, r, k);
    if (r >  mid) updmul(p<<1|1, l, r, k);
    pushup(p);
}

void updadd(int p, int l, int r, int k) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) += k * len(p); dat(p) %= mod;
        add(p) += k; add(p) %= mod;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) updadd(p<<1, l, r, k);
    if (r >  mid) updadd(p<<1|1, l, r, k);
    pushup(p);
}

LL query(int p, int l, int r) {
    if (l <= l(p) && r >= r(p)) return dat(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    LL ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &mod);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int opt; scanf("%d", &opt);
        int x, y; LL k;
        switch (opt) {
            case 1:
                scanf("%d %d %lld", &x, &y, &k);
                updmul(1, x, y, k % mod);
                break;
            case 2:
                scanf("%d %d %lld", &x, &y, &k);
                updadd(1, x, y, k % mod);
                break;
            case 3:
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(1, x, y) % mod);
                break;
        }
    }
    return 0;
}