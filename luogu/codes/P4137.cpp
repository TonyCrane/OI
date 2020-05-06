/*************************************************************
 *  > File Name        : P4137.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/05/06 14:17:25
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

int n, m, l, r, len, Ans;
int a[maxn], ans[maxn], cnt[maxn];

struct Query {
    int l, r, id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}

void add(int x) {
    if (a[x] > maxn) return;
    if (!cnt[a[x]]++ && Ans == a[x]) {
        while (++Ans) if (!cnt[Ans]) return;
    }
}
void del(int x) {
    if (!--cnt[a[x]]) Ans = min(Ans, a[x]);
}

bool flag = true;
int main() {
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i; q[i].pos = (q[i].l - 1) / len;
        if (q[i].r != 200000) flag = false;
    }
    if (flag) { for (int i = 1; i <= m; ++i)
        if (q[i].l == 1) printf("200000\n");
        else printf("0\n");
        return 0;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}