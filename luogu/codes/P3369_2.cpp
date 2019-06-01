/*************************************************************
 *  > File Name        : P3369_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 15:31:07
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

const int maxn = 100010;
const int inf  = 0x7fffffff;
int n;

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
}treap;

int main() {
    treap.build();
    treap.n = n = read();
    while (n--) {
        int opt = read(), x = read();
        if      (opt == 1) treap.insert(treap.root, x);
        else if (opt == 2) treap.Remove(treap.root, x);
        else if (opt == 3) printf("%d\n", treap.GetRankByVal(treap.root, x) - 1);
        else if (opt == 4) printf("%d\n", treap.GetValByRank(treap.root, x + 1));
        else if (opt == 5) printf("%d\n", treap.GetPre(x));
        else if (opt == 6) printf("%d\n", treap.GetNext(x));
    }
    return 0;
}