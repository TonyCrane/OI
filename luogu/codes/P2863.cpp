/*************************************************************
 *  > File Name        : P2863.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/29 16:18:20
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

const int maxn = 10010;

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

int n, m, num[maxn], ans;
int low[maxn], dfn[maxn], dfnc, color[maxn];
stack<int> s; bool ins[maxn];
vector<int> scc[maxn]; int cnt;

void Tarjan(int x) {
    low[x] = dfn[x] = ++dfnc;
    s.push(x); ins[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            Tarjan(e.to);
            low[x] = min(low[x], low[e.to]);
        } else if (ins[e.to]) {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
    if (low[x] == dfn[x]) {
        cnt++; int y;
        do {
            y = s.top(); s.pop(); ins[y] = false;
            color[y] = cnt; scc[cnt].push_back(y);
        } while (x != y);
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i = 1; i <= n; ++i) {
        num[color[i]]++;
    }
    for (int i = 1; i <= cnt; ++i) {
        if (num[i] > 1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}