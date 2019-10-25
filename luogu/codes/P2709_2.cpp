/*************************************************************
 *  > File Name        : P2709_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/25 20:45:44
 *  > Algorithm        : Mo's algorithm
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

struct Query {
    int l, r, pos, id;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}

int n, m, k, len, l, r, Ans;
int ans[maxn], c[maxn], cnt[maxn];

void del(int x) {
    Ans -= cnt[c[x]] * cnt[c[x]];
    cnt[c[x]]--;
    Ans += cnt[c[x]] * cnt[c[x]];
}

void add(int x) {
    Ans -= cnt[c[x]] * cnt[c[x]];
    cnt[c[x]]++;
    Ans += cnt[c[x]] * cnt[c[x]];
}

int main() {
    n = read(); m = read(); k = read();
    len = sqrt(n);
    for (int i = 1; i <= n; ++i) c[i] = read();
    for (int i = 1; i <= m; ++i) {
        q[i].id = i;
        q[i].l = read();
        q[i].r = read();
        q[i].pos = q[i].l / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) del(l++);
        while (l > q[i].l) add(--l);
        while (r > q[i].r) del(r--);
        while (r < q[i].r) add(++r);
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}