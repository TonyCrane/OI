/*************************************************************
 *  > File Name        : P5906.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/30 10:19:03
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

const int maxn = 200010;

int n, m, l, r, Ans, len;
int a[maxn], old[maxn], fst[maxn], lst[maxn];
int rpos[maxn], ans[maxn];

struct Query {
    int l, r, id, pos;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    return a.r < b.r;
}

int solve(int l, int r) {
    int res = 0, last[maxn]; memset(last, 0, sizeof(last));
    for (int i = l; i <= r; ++i) {
        if (!last[a[i]]) last[a[i]] = i;
        else res = max(res, i - last[a[i]]);
    }
    return res;
}

int main() {
    n = read(); len = sqrt(n); int num = ceil((double)n / len);
    for (int i = 1; i <= num; ++i) rpos[i] = len * i; rpos[num] = n;
    for (int i = 1; i <= n; ++i) old[i] = a[i] = read();
    sort(old + 1, old + 1 + n);
    int len_ = unique(old + 1, old + 1 + n) - old - 1;
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(old + 1, old + 1 + len_, a[i]) - old;
    m = read();
    for (int i = 1; i <= m; ++i) {
        q[i].l = read(); q[i].r = read();
        q[i].id = i; q[i].pos = (q[i].l - 1) / len + 1;
    }
    sort(q + 1, q + 1 + m, cmp); l = 1;
    for (int k = 1, i = 1; k <= num; ++k) {
        l = rpos[k] + 1; r = rpos[k]; Ans = 0;
        memset(lst, 0, sizeof(lst)); memset(fst, 0, sizeof(fst));
        while (q[i].pos == k) {
            if (q[i].l / len == q[i].r / len) {
                ans[q[i].id] = solve(q[i].l, q[i].r);
                i++; continue;
            }
            while (r < q[i].r) {
                lst[a[++r]] = r;
                if (!fst[a[r]]) fst[a[r]] = r;
                Ans = max(Ans, r - fst[a[r]]);
            }
            int tmp = Ans;
            while (l > q[i].l) {
                if (lst[a[--l]]) Ans = max(Ans, lst[a[l]] - l);
                else lst[a[l]] = l;
            }
            ans[q[i].id] = Ans;
            while (l < rpos[k] + 1) {
                if (lst[a[l]] == l) lst[a[l]] = 0; l++;
            }
            Ans = tmp; i++;
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}