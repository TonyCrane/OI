/*************************************************************
 *  > File Name        : CF86D.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/27 11:49:13
 *  > Algorithm        : Mo's Algorithm
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 200010;

LL n, t, l, r, len, Ans;
LL a[maxn], cnt[1000010], ans[maxn];

struct Query {
    LL l, r, id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}

void add(LL x) {
    Ans -= cnt[a[x]] * cnt[a[x]] * a[x];
    cnt[a[x]]++;
    Ans += cnt[a[x]] * cnt[a[x]] * a[x];
}

void del(LL x) {
    Ans -= cnt[a[x]] * cnt[a[x]] * a[x];
    cnt[a[x]]--;
    Ans += cnt[a[x]] * cnt[a[x]] * a[x];
}

int main() {
    n = read(); t = read(); len = sqrt(n);
    for (LL i = 1; i <= n; ++i) a[i] = read();
    for (LL i = 1; i <= t; ++i) {
        q[i].l = read(); 
        q[i].r = read();
        q[i].id = i;
        q[i].pos = q[i].l / len + 1;
    }
    sort(q + 1, q + 1 + t, cmp); l = 1;
    for (LL i = 1; i <= t; ++i) {
        while (l < q[i].l) del(l++);
        while (l > q[i].l) add(--l);
        while (r > q[i].r) del(r--);
        while (r < q[i].r) add(++r);
        ans[q[i].id] = Ans;
    }
    for (LL i = 1; i <= t; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}