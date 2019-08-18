/*************************************************************
 *  > File Name        : P3366_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/17 15:52:55
 *  > Algorithm        : [Graph]Kruskal
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5010;
const int maxm = 200010;

int ufs[maxn];
int find(int x) {
    if (ufs[x] == x) return x;
    return ufs[x] = find(ufs[x]);
}

struct Edge {
    int from, to, val;
} edges[maxm];

bool cmp(Edge a, Edge b) {
    if (a.val != b.val) return a.val < b.val;
    if (a.from != b.from) return a.from < b.from;
    return a.to < b.to;
}

int ans = 0, n, m, cnt = 1;

void Kruskal() {
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    sort(edges, edges + m, cmp);
    for (int i = 0; i < m; ++i) {
        int x = find(edges[i].from);
        int y = find(edges[i].to);
        if (x != y) {
            ufs[x] = y; cnt++;
            ans += edges[i].val;
        }
    }
}

int main() {
    n = read(), m = read();
    for (int i = 0; i < m; ++i) {
        edges[i].from = read();
        edges[i].to   = read();
        edges[i].val  = read();
    }
    Kruskal();
    if (cnt == n) {
        printf("%d\n", ans);
    } else {
        printf("orz\n");
    }
    return 0;
}