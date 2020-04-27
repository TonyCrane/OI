/*************************************************************
 *  > File Name        : P3901.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/27 14:01:41
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

const int maxn = 100010;

struct Query {
    int l, r, pos, id;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r > b.r;
    return a.r < b.r;
}

int n, m, len, l, r, Ans;
int ans[maxn], a[maxn], cnt[maxn];

void add(int x) {
    if (cnt[a[x]] == 0) Ans++;
    cnt[a[x]]++;
}
void del(int x) {
    if (cnt[a[x]] == 1) Ans--;
    cnt[a[x]]--;
}

int main() {
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) a[i] = read();
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
        if (Ans == r - l + 1) ans[q[i].id] = 1;
        else ans[q[i].id] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        printf(ans[i] == 1 ? "Yes\n" : "No\n");
    }
    return 0;
}