/*************************************************************
 *  > File Name        : c1081_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/31 12:32:26
 *  > Algorithm        : sort
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

const LL maxn = 7010;

struct Node {
    LL id, pos, v, s;
    bool operator < (const Node& a) const {
        if (pos == a.pos) return id < a.id;
        return pos > a.pos;
    }
}a[maxn];

struct Query {
    int t, k, id;
    bool operator < (const Query& a) const {
        return t < a.t;
    }
}q[maxn];

LL n, m, ans[maxn];

int main() {
    // freopen("race.in", "r", stdin);
    // freopen("race.out", "w", stdout);
    n = read();
    for (LL i = 1; i <= n; ++i) {
        a[i].v = read(); a[i].s = read(); a[i].id = i;
    }
    m = read();
    for (int i = 1; i <= m; ++i) {
        q[i].t = read(); q[i].k = read(); q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    for (int i = 1; i <= n; ++i) {
        a[i].pos = a[i].s + a[i].v * q[1].t;
    }
    sort(a + 1, a + 1 + n);
    ans[q[1].id] = a[q[1].k].id;
    for (LL i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[j].pos = a[j].s + a[j].v * q[i].t;
        }
        for (int i = 2; i <= n; ++i) {
            int t = i;
            while (t > 1 && a[t] < a[t - 1]) {
                swap(a[t], a[t - 1]);
                t--;
            }
        }
        ans[q[i].id] = a[q[i].k].id;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}