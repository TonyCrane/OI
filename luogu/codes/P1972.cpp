/*************************************************************
 *  > File Name        : P1972.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/28 15:11:19
 *  > Algorithm        : BIT离线
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;

int n, m, nxt = 1;
int a[maxn], t[maxn], vis[maxn], ans[maxn];

struct Query {
    int l, r, id;
}q[maxn];

bool cmp(Query a, Query b) {
    return a.r < b.r;
}

void add(int x, int k) {
    for (; x <= n; x += x & -x) t[x] += k;
}
int ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += t[x];
    return res;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    m = read();
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m, cmp);
    for (int i = 1; i <= m; ++i) {
        for (int j = nxt; j <= q[i].r; ++j) {
            if (vis[a[j]]) {
                add(vis[a[j]], -1);
            }
            add(j, 1);
            vis[a[j]] = j;
        }
        nxt = q[i].r + 1;
        ans[q[i].id] = ask(q[i].r) - ask(q[i].l - 1);
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}