/*************************************************************
 *  > File Name        : AT1219.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/30 07:55:14
 *  > Algorithm        : 回滚莫队
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

int n, m, len, l, r;
int a[maxn], cnt[maxn], rpos[maxn], old[maxn], cnt2[maxn];
LL Ans, ans[maxn];

struct Query {
    int l, r, id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    return a.r < b.r;
}

LL solve(int l, int r) {
    LL res = 0;
    for (int i = l; i <= r; ++i) cnt2[a[i]] = 0;
    for (int i = l; i <= r; ++i) {
        cnt2[a[i]]++;
        res = max(res, 1LL * cnt2[a[i]] * old[a[i]]);
    }
    return res;
}

void add(int x) {
    cnt[a[x]]++;
    Ans = max(Ans, 1LL * cnt[a[x]] * old[a[x]]);
}

signed main() {
    n = read(); m = read(); len = sqrt(n); int num = ceil((double)n / len);
    for (int i = 1; i <= num; ++i) rpos[i] = len * i; rpos[num] = n;
    for (int i = 1; i <= n; ++i) old[i] = a[i] = read();
    sort(old + 1, old + 1 + n);
    int len_ = unique(old + 1, old + 1 + n) - old - 1;
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(old + 1, old + 1 + len_, a[i]) - old;
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i; q[i].pos = (q[i].l - 1) / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int k = 1, i = 1; k <= num; ++k) {
        l = rpos[k] + 1, r = rpos[k], Ans = 0;
        memset(cnt, 0, sizeof(cnt));
        while (q[i].pos == k) {
            if (q[i].l / len == q[i].r / len) {
                ans[q[i].id] = solve(q[i].l, q[i].r);
                i++; continue;
            }
            while (r < q[i].r) add(++r);
            LL tmp = Ans;
            while (l > q[i].l) add(--l);
            ans[q[i].id] = Ans;
            while (l < rpos[k] + 1) cnt[a[l++]]--;
            Ans = tmp; i++;
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}