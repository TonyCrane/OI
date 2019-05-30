/*************************************************************
 *  > File Name        : SP2916.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/30 15:02:05
 *  > Algorithm        : [DataStructure]SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;
#define lt p<<1
#define rt p<<1|1

struct SegmentTree {
    int l, r, pre, bat, suf, sum;
    #define l(x)   tree[x].l
    #define r(x)   tree[x].r
    #define pre(x) tree[x].pre
    #define bat(x) tree[x].bat
    #define suf(x) tree[x].suf
    #define sum(x) tree[x].sum
} tree[maxn * 4];
int a[maxn];

void update(int p) {
    sum(p) = sum(lt) + sum(rt);
    bat(p) = max(bat(lt), bat(rt));
    bat(p) = max(bat(p), suf(lt) + pre(rt));
    pre(p) = max(sum(lt) + pre(rt), pre(lt));
    suf(p) = max(sum(rt) + suf(lt), suf(rt));
}

void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        pre(p) = bat(p) = suf(p) = sum(p) = a[l] = read();
        return;
    }
    int mid = (l(p) + r(p)) >> 1;
    build(lt, l, mid);
    build(rt, mid + 1, r);
    update(p);
}

SegmentTree query(int p, int l, int r) {
    int mid = (l(p) + r(p)) >> 1;
    if (l > r) return (SegmentTree){0, 0, 0, 0, 0, 0};
    if (l <= l(p) && r >= r(p)) return tree[p];
    if (l >  mid) return query(rt, l, r);
    if (r <= mid) return query(lt, l, r);
    SegmentTree ans, aa, bb;
    aa = query(lt, l, r); bb = query(rt, l, r);
    ans.bat = max(aa.bat, bb.bat);
    ans.bat = max(ans.bat, aa.suf + bb.pre);
    ans.pre = max(aa.pre, aa.sum + bb.pre);
    ans.sum = aa.sum + bb.sum;
    ans.suf = max(bb.suf, bb.sum + aa.suf);
    return ans;
}

void solve() {
    int n = read(); build(1, 1, n); int m = read();
    for (int i = 1; i <= m; ++i) {
        int ll = read(), lr = read(), rl = read(), rr = read();
        if (lr < rl) {
            printf("%d\n", query(1, ll, lr).suf + query(1, lr + 1, rl - 1).sum + query(1, rl, rr).pre);
        } else {
            int ans = query(1, rl, lr).bat;
            if (ll < rl) ans = max(ans, query(1, ll, rl).suf + query(1, rl, rr).pre - a[rl]);
            if (rr > lr) ans = max(ans, query(1, ll, lr).suf + query(1, lr, rr).pre - a[lr]);
            printf("%d\n", ans);
        }
    }
    return;
}

int main() {
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}