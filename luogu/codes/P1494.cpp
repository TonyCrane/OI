/*************************************************************
 *  > File Name        : P1494.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/27 14:30:42
 *  > Algorithm        : 莫队
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }

const int maxn = 50010;

struct Query {
    int l, r, pos, id;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}
struct Answer {
    LL a, b;
}ans[maxn];

int n, m, l, r, Ans, len;
LL c[maxn], cnt[maxn];

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
    n = read(); m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) c[i] = read();
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
        if (l == r) {
            ans[q[i].id].a = 0; ans[q[i].id].b = 1;
            continue;
        }
        LL a = Ans - (r - l + 1);
        LL b = 1LL * (r - l + 1) * (LL)(r - l);
        LL g = gcd(a, b);
        ans[q[i].id].a = a / g;
        ans[q[i].id].b = b / g;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%lld/%lld\n", ans[i].a, ans[i].b);
    }
    return 0;
}