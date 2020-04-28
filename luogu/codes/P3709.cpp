/*************************************************************
 *  > File Name        : P3709.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/28 12:58:52
 *  > Algorithm        : 莫队
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

struct Query {
    int l, r, id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r; 
}

int n, m, l, r, len, Ans;
int a[maxn], old[maxn], cnt[maxn], times[maxn], ans[maxn];

void add(int x) {
    if (Ans == cnt[a[x]]) Ans++;
    times[cnt[a[x]]]--;
    times[++cnt[a[x]]]++;
}
void del(int x) {
    if (cnt[a[x]] == Ans && times[cnt[a[x]]] == 1) Ans--;
    times[cnt[a[x]]]--;
    times[--cnt[a[x]]]++;
}

int main() {
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        old[i] = a[i] = read();
    }
    sort(old + 1, old + 1 + n);
    int len_ = unique(old + 1, old + 1 + n) - old - 1;
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(old + 1, old + 1 + len_, a[i]) - old;
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i; q[i].pos = q[i].l / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        ans[q[i].id] = -Ans;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}