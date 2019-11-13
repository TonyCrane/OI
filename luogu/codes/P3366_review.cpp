/*************************************************************
 *  > File Name        : P3366_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 07:57:13
 *  > Algorithm        : review Kruskal
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

struct Edge {
    int from, to, val;
}edges[maxm];
bool cmp(Edge a, Edge b) {
    if (a.val != b.val) return a.val < b.val;
    if (a.from != b.from) return a.from < b.from;
    return a.to < b.to;
}

int ufs[maxn], ans, cnt = 1, n, m;
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }

void Kruskal() {
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    sort(edges + 1, edges + 1 + m, cmp);
    for (int i = 1; i <= m; ++i) {
        int x = find(edges[i].from);
        int y = find(edges[i].to);
        if (x != y) {
            ufs[x] = y; cnt++;
            ans += edges[i].val;
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
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