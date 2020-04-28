/*************************************************************
 *  > File Name        : P1903.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/28 14:33:50
 *  > Algorithm        : 带修莫队
**************************************************************/

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 140000;

int n, m, l, r, t, len, cntq, cntr, Ans;
int a[maxn], cnt[1000010], ans[maxn], block[maxn];

struct Query {
    int l, r, t, id;
}q[maxn];
bool cmp(Query a, Query b) {
    if (block[a.l] != block[b.l]) return block[a.l] < block[b.l];
    if (block[a.r] != block[b.r]) return block[a.r] < block[b.r];
    return a.t < b.t;
}

struct Change {
    int pos, color;
}c[maxn];

void add(int x) {
    if (cnt[a[x]] == 0) Ans++;
    cnt[a[x]]++;
}
void del(int x) {
    if (cnt[a[x]] == 1) Ans--;
    cnt[a[x]]--;
}
void chg(int t) {
    if (l <= c[t].pos && c[t].pos <= r) {
        del(c[t].pos);
        if (cnt[c[t].color] == 0) Ans++;
        cnt[c[t].color]++;
    }
    swap(a[c[t].pos], c[t].color);
}

int main() {
    n = read(); m = read(); len = pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        block[i] = (i - 1) / len + 1;
    }
    for (int i = 1; i <= m; ++i) {
        char opt[10]; scanf("%s", opt);
        if (opt[0] == 'Q') {
            q[++cntq].l = read(); q[cntq].r = read();
            q[cntq].id = cntq; q[cntq].t = cntr;
        } else {
            c[++cntr].pos = read();
            c[cntr].color = read();
        }
    }
    sort(q + 1, q + 1 + cntq, cmp); l = 1;
    for (int i = 1; i <= cntq; ++i) {
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        while (t < q[i].t) chg(++t);
        while (t > q[i].t) chg(t--);
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= cntq; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}