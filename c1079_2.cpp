/*************************************************************
 *  > File Name        : c1079_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/25 15:40:29
 *  > Algorithm        : 
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

int n, m, len, a[maxn], l, r, ans[maxn];

struct Query {
    int l, r, p, v;
    int id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) a.pos < b.pos;
    return a.r < a.r;
}

int cnt[maxn];

void add(int x) { cnt[a[x]]++; }
void del(int x) { cnt[a[x]]--; }

int main() {
    n = read(), m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) {
        q[i].l = read();
        q[i].r = read();
        q[i].p = read();
        q[i].v = read();
        q[i].id = i;
        q[i].pos = q[i].l / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) del(l++);
        while (l > q[i].l) add(--l);
        while (r > q[i].r) del(r--);
        while (r < q[i].r) add(++r);
        int Ans = 0, k = 0;
        while (q[i].p * k + q[i].v <= 10000) {
            Ans += cnt[q[i].p * k + q[i].v];
            k++;
        } 
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}