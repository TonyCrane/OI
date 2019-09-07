/*************************************************************
 *  > File Name        : P2341.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/07 14:34:20
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

bool ins[maxn];
int num, cnt;
int dfn[maxn], low[maxn], c[maxn];
vector<int> scc[maxn];
stack<int> s;

void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    s.push(x); ins[x] = true;
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
            y = s.top(); s.pop();
            c[y] = cnt; scc[cnt].push_back(y);
        } while (x != y);
    }
}

int n, m, deg[maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            Edge& e = edges[G[i][j]];
            if (c[i] != c[e.to]) {
                deg[c[i]]++;
            }
        }
    }
    int ans = 0; bool flag = false;
    for (int i = 1; i <= cnt; ++i) {
        if (deg[i] == 0) {
            if (ans) flag = true;
            ans = i;
        }
    }
    if (flag) puts("0");
    else printf("%d\n", scc[ans].size());
    return 0;
}