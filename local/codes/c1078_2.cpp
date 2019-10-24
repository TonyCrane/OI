/*************************************************************
 *  > File Name        : graph.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/23 15:51:27
 *  > Algorithm        : 
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

int n, m, k;

struct Edge {
    int from, to, val;
    Edge() {}
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
}e[maxn];
bool cmp(Edge a, Edge b) {
    return a.val < b.val;
}

int ufs[maxn], siz[maxn];
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
void unionn(int x, int y) {
    ufs[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
}

int val[maxn], cnt, ans[maxn];

int query(int x) {
    int l = 1, r = cnt, res;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (val[mid] <= x) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return res;
}

int main() {
    // freopen("Graph.in", "r", stdin);
    // freopen("Graph.out", "w", stdout);
    n = read(); m = read(); k = read();
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        e[i].from = u;
        e[i].to = v;
        e[i].val = w;
    }
    sort(e + 1, e + 1 + m, cmp);
    int now = 1;
    for (int i = 1; i <= m; ++i) {
        if (e[i].val != e[i - 1].val) val[++cnt] = e[i].val;
    }
    for (int i = 1; i <= cnt; ++i) {
        ans[i] = ans[i - 1];
        int nowval = val[i];
        for (; e[now].val <= nowval && now <= m; ++now) {
            int fx = find(e[now].from), fy = find(e[now].to);
            if (fx == fy) {
                ans[i] = max(ans[i], siz[fy] + e[now].val);
                siz[fy] += e[now].val;
            } else {
                siz[fx] += e[now].val;
                ans[i] = max(ans[i], siz[fx] + siz[fy]);
                unionn(fx, fy);
            }
        }
    }
    while (k--) {
        int x = read();
        printf("%d\n", ans[query(x)]);
    }
    return 0;
}