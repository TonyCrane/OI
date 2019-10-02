/*************************************************************
 *  > File Name        : P2746.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/26 12:38:21
 *  > Algorithm        : Tarjan
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int dfn[maxn], low[maxn], c[maxn], degI[maxn], degO[maxn];
int val[maxn], sum[maxn], n, m, num, cnt, ans1, ans2;
stack<int> s; bool ins[maxn];
vector<int> scc[maxn];

void tarjan(int x) {
    dfn[x] = low[x] = ++num; s.push(x); ins[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            tarjan(e.to);
            low[x] = min(low[x], low[e.to]);
        } else if (ins[e.to]) {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
    if (dfn[x] == low[x]) {
        cnt++; int y;
        do {
            y = s.top(); s.pop(); ins[y] = false;
            c[y] = cnt; scc[cnt].push_back(y);
            sum[cnt] += val[y];
        } while (x != y);
    }
}

int main() {
    n = read(); int tot = 0;
    for (int u = 1; u <= n; ++u) {
        int v;
        while (cin >> v && v) {
            add(u, v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (c[u] != c[e.to]) {
                degI[c[e.to]]++;
                degO[c[u]]++;
            }
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        if (degI[i] == 0) ans1++;
        if (degO[i] == 0) ans2++;
    }
    if (cnt == 1) printf("1\n0\n");
    else printf("%d\n%d\n", ans1, max(ans1, ans2));
    return 0;
}