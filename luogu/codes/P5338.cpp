/*************************************************************
 *  > File Name        : P5338.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/16 13:37:15
 *  > Algorithm        : Treap
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;

UI last = 7, seed, m;

UI randNum(UI& seed, UI last, const UI m) {
    seed = seed * 17 + last;
    return seed % m + 1;
}

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;
const int inf  = 0x3f3f3f3f;

struct Node {
    int l, r;
    int acn, tim, dat;
    int cnt, siz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define acn(p) tree[p].acn
    #define tim(p) tree[p].tim
    #define dat(p) tree[p].dat
    #define cnt(p) tree[p].cnt
    #define siz(p) tree[p].siz
}tree[maxn];
int tot, root, n;
int New(int a, int t) {
    tot++;
    acn(tot) = a; tim(tot) = t;
    dat(tot) = rand();
    cnt(tot) = 1;
    siz(tot) = 1;
    return tot;
}
void update(int p) {
    siz(p) = siz(l(p)) + siz(r(p)) + cnt(p);
}
void build() {
    tot = 0;
    New(inf, -inf); New(-inf, inf);
    root = 1; tree[1].r = 2;
    update(root);
}
int GetRankByVal(int p, int a, int t) {
    if (p == 0) return 0;
    if (a == acn(p) && t == tim(p)) return siz(l(p)) + 1;
    if (a >  acn(p) || (a == acn(p) && t < tim(p))) return GetRankByVal(l(p), a, t);
    return GetRankByVal(r(p), a, t) + siz(l(p)) + cnt(p);
}
void zig(int& p) {
    int q = l(p);
    l(p) = r(q); r(q) = p; p = q;
    update(r(p)); update(p);
}
void zag(int& p) {
    int q = r(p);
    r(p) = l(q); l(q) = p; p = q;
    update(l(p)); update(p);
}
void insert(int& p, int a, int t) {
    if (p == 0) {
        p = New(a, t);
        return;
    }
    if (a == acn(p) && t == tim(p)) {
        cnt(p)++; update(p);
        return;
    }
    if (a > acn(p) || (a == acn(p) && t < tim(p))) {
        insert(l(p), a, t);
        if (dat(p) < dat(l(p))) zig(p);
    } else {
        insert(r(p), a, t);
        if (dat(p) < dat(r(p))) zag(p);
    }
    update(p);
}
void remove(int& p, int a, int t) {
    if (p == 0) return;
    if (a == acn(p) && t == tim(p)) {
        if (cnt(p) > 1) {
            cnt(p)--; update(p);
            return;
        }
        if (l(p) || r(p)) {
            if (r(p) == 0 || dat(l(p) > dat(r(p)))) {
                zig(p); remove(r(p), a, t);
            } else {
                zag(p); remove(l(p), a, t);
            }
            update(p);
        } else p = 0;
        return;
    }
    if (a > acn(p) || (a == acn(p) && t < tim(p))) {
        remove(l(p), a, t);
    } else {
        remove(r(p), a, t);
    }
    update(p);
}

int acn[maxn], tim[maxn];

void init() {
    memset(tree, 0, sizeof(tree));
    build();
    memset(acn, 0, sizeof(acn));
    memset(tim, 0, sizeof(tim));
}

int main() {
    srand((int)time(NULL));
    int T = read();
    while (T--) {
        init();
        m = read(), n = read(), seed = read();
        for (int i = 1; i <= n; ++i) {
            int ria = randNum(seed, last, m), rib = randNum(seed, last, m);
            remove(root, acn[ria], tim[ria]);
            acn[ria]++; tim[ria] += rib;
            insert(root, acn[ria], tim[ria]);
            printf("%d\n", last = GetRankByVal(root, acn[ria], tim[ria]) - 2);
        }
    }
    return 0;
}