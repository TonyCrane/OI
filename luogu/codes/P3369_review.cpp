/*************************************************************
 *  > File Name        : P3369_review.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/12 21:26:10
 *  > Algorithm        : review Treap
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

struct Treap {
    int l, r, val, dat, cnt, siz;
    #define l(p) a[p].l
    #define r(p) a[p].r
    #define val(p) a[p].val
    #define dat(p) a[p].dat
    #define cnt(p) a[p].cnt
    #define siz(p) a[p].siz
}a[maxn];

int tot, root, n;

int New(int val) {
    val(++tot) = val;
    dat(tot)   = rand();
    cnt(tot)   = 1;
    siz(tot)   = 1;
    return tot;
}

void update(int p) {
    siz(p) = siz(l(p)) + cnt(p) + siz(r(p));
}

void build() {
    New(-inf); New(inf);
    root = 1; r(1) = 2;
    update(root);
}

int getRankByVal(int p, int val) {
    if (p == 0) return 0;
    if (val == val(p)) return siz(l(p)) + 1;
    if (val <  val(p)) return getRankByVal(l(p), val);
    return getRankByVal(r(p), val) + siz(l(p)) + cnt(p);
}

int getValByRank(int p, int rank) {
    if (p == 0) return inf;
    if (siz(l(p)) >= rank) return getValByRank(l(p), rank);
    if (siz(l(p)) + cnt(p) >= rank) return val(p);
    return getValByRank(r(p), rank - siz(l(p)) - cnt(p));
}

void zig(int& p) {
    int q = l(p);
    l(p) = r(q); r(q) = p; p = q;
    update(r(p)); update(p);
}

void zag(int & p) {
    int q = r(p);
    r(p) = l(q); l(q) = p; p = q;
    update(l(p)); update(p);
}

void insert(int& p, int val) {
    if (p == 0) {
        p = New(val);
        return;
    }
    if (val == val(p)) {
        cnt(p)++;
        update(p);
        return;
    }
    if (val < val(p)) {
        insert(l(p), val);
        if (dat(p) < dat(l(p))) zig(p);
    } else {
        insert(r(p), val);
        if (dat(p) < dat(r(p))) zag(p);
    }
    update(p);
}

int getPre(int val) {
    int ans = 1, p = root;
    while (p) {
        if (val == val(p)) {
            if (l(p) > 0) {
                p = l(p);
                while (r(p) > 0) p = r(p);
                ans = p;
            }
            break;
        }
        if (val(p) < val && val(p) > val(ans)) ans = p;
        p = val < val(p) ? l(p) : r(p);
    }
    return val(ans);
}

int getSuf(int val) {
    int ans = 2, p = root;
    while (p) {
        if (val == val(p)) {
            if (r(p) > 0) {
                p = r(p);
                while (l(p) > 0) p = l(p);
                ans = p;
            }
            break;
        }
        if (val(p) > val && val(p) < val(ans)) ans = p;
        p = val < val(p) ? l(p) : r(p);
    }
    return val(ans);
}

void remove(int& p, int val) {
    if (p == 0) return;
    if (val == val(p)) {
        if (cnt(p) > 1) {
            cnt(p)--; update(p);
            return;
        }
        if (l(p) || r(p)) {
            if (r(p) == 0 || dat(l(p)) > dat(r(p))) {
                zig(p); remove(r(p), val);
            } else {
                zag(p); remove(l(p), val);
            }
            update(p);
        } else p = 0;
        return;
    }
    if (val < val(p)) remove(l(p), val);
    else remove(r(p), val);
    update(p);
}

int main() {
    srand((int)time(NULL));
    n = read();
    build();
    while (n--) {
        int opt = read(), x = read();
        if      (opt == 1) insert(root, x);
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", getRankByVal(root, x) - 1);
        else if (opt == 4) printf("%d\n", getValByRank(root, x + 1));
        else if (opt == 5) printf("%d\n", getPre(x));
        else if (opt == 6) printf("%d\n", getSuf(x));
    }
    return 0;
}