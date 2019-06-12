/*************************************************************
 *  > File Name        : P2286.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/12 12:59:24
 *  > Algorithm        : [DataStructure]Treap
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 80010;
const int inf  = 0x3f3f3f3f;
const int mod  = 1000000;

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
} treap;

int main() {
    int n = read(), cnt = 0, ans = 0, flag;
    treap.build();
    for (int i = 1; i <= n; ++i) {
        int a = read(), b = read();
        if (cnt == 0) {
            flag = a;
            treap.insert(treap.root, b);
            cnt++;
        } else {
            if (a == flag) {
                treap.insert(treap.root, b);
                cnt++;
            } else {
                cnt--;
                int p = treap.GetPre(b), s = treap.GetNext(b);
                if (b - p <= s - b) {
                    ans += b - p;
                    ans %= mod;
                    treap.Remove(treap.root, p);
                } else {
                    ans += s - b;
                    ans %= mod;
                    treap.Remove(treap.root, s);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}