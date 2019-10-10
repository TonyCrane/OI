/*************************************************************
 *  > File Name        : c1073_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/10 15:08:22
 *  > Algorithm        : 30Points
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
    int l, r, id;
}q[maxn];
bool cmp(Query a, Query b) {
    return a.r < b.r;
}

int n, m, p[maxn], ans[maxn], pos[maxn];
int t[maxn];
void add(int x, int k) {
    for (; x <= n; x += x & -x) t[x] += k;
}
int ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += t[x];
    return res;
}

void rev() {
    reverse(p + 1, p + 1 + n);
    for (int i = 1; i <= n; ++i) {
        pos[i] = n + 1 - pos[i];
    }
    for (int i = 1; i <= m; ++i) {
        int tmp = q[i].r;
        q[i].r = n + 1 - q[i].l;
        q[i].l = n + 1 - tmp;
    }
    sort(q + 1, q + 1 + m, cmp);
    memset(t, 0, sizeof(t));
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        p[i] = read();
        pos[p[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        q[i].l = read();
        q[i].r = read();
        q[i].id = i;
        ans[i] = q[i].r - q[i].l + 1;
    }
    sort(q + 1, q + 1 + m, cmp);
    for (int i = 1; i <= m; ++i) {
        for (int j = q[i - 1].r + 1; j <= q[i].r; ++j)
            for (int k = 2; k <= n / p[j]; ++k)
                if (pos[k * p[j]] < j) add(pos[k * p[j]], 1);
        ans[q[i].id] += ask(q[i].r) - ask(q[i].l - 1);
    }
    rev();
    for (int i = 1; i <= m; ++i) {
        for (int j = q[i - 1].r + 1; j <= q[i].r; ++j)
            for (int k = 2; k <= n / p[j]; ++k)
                if (pos[k * p[j]] < j) add(pos[k * p[j]], 1);
        ans[q[i].id] += ask(q[i].r) - ask(q[i].l - 1);
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}