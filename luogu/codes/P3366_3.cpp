/*************************************************************
 *  > File Name        : P3366_3.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/17 16:05:59
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

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}
bool cmp(Edge a, Edge b) {
    if (a.val != b.val) return a.val < b.val;
    if (a.from != b.from) return a.from < b.from;
    return a.to < b.to;
}

int ufs[maxn], n, m, ans = 0, cnt = 1;
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }

void Kruskal() {
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 0; i < m; ++i) {
        Edge& e = edges[i];
        int x = find(e.from), y = find(e.to);
        if (x != y) {
            ufs[x] = y;
            ans += e.val;
            cnt++;
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    Kruskal();
    if (cnt == n) printf("%d\n", ans);
    else printf("orz\n");
    return 0;
}