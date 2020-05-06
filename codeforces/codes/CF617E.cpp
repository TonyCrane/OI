/*************************************************************
 *  > File Name        : CF617E.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/05/06 14:38:35
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

const int maxn = 100010;

int n, m, l, r, len, k;
int a[maxn], cnt[1200010];
LL Ans, ans[maxn];

struct Query {
    int l, r, id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r < b.r;
    return a.r > b.r;
}

void add(int x) {
    Ans += (LL)cnt[a[x] ^ k];
    cnt[a[x]]++;
}
void del(int x) {
    cnt[a[x]]--;
    Ans -= (LL)cnt[a[x] ^ k];
}

int main() {
    n = read(); m = read(); k = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) a[i] = read() ^ a[i - 1];
    for (int i = 1; i <= m; ++i) {
        q[i].l = read() - 1; q[i].r = read();
        q[i].id = i; q[i].pos = (q[i].l - 1) / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 0; cnt[0] = 1;
    for (int i = 1; i <= m; ++i) {
        while (l < q[i].l) del(l++);
        while (r > q[i].r) del(r--);
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        ans[q[i].id] = Ans;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}