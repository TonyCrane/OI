/*************************************************************
 *  > File Name        : P3674.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/05/07 07:34:40
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

bitset<maxn> s1, s2;
int n, m, l, r, len, Ans;
int a[maxn], cnt[maxn], ans[maxn];

struct Query {
    int l, r, id, pos, opt, x;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}

void add(int x) {
    if (!cnt[a[x]]++) s1[a[x]] = s2[n - a[x]] = true;
}
void del(int x) {
    if (!--cnt[a[x]]) s1[a[x]] = s2[n - a[x]] = false;
}

int main() {
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) {
        q[i].opt = read(); q[i].l = read(); q[i].r = read(); q[i].x = read();
        q[i].id = i; q[i].pos = (q[i].l - 1) / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        if (q[i].opt == 1) {
            ans[q[i].id] = (s1 & (s1 << q[i].x)).any();
        } else if (q[i].opt == 2) {
            ans[q[i].id] = (s1 & (s2 >> (n - q[i].x))).any();
        } else {
            for (int j = 1; j * j <= q[i].x; ++j) if (!(q[i].x % j)) {
                if (s1[j] && s1[q[i].x / j]) {
                    ans[q[i].id] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf(ans[i] ? "hana\n" : "bi\n");
    }
    return 0;
}