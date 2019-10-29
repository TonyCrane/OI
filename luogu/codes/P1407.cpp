/*************************************************************
 *  > File Name        : P1407.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/28 21:42:19
 *  > Algorithm        : Tarjan
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

int n, m;
map<string, int> _map;

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

int dfn[maxn], low[maxn], dfnc, color[maxn];
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        string girl, boy;
        cin >> girl >> boy;
        _map[girl] = i; _map[boy] = i + n;
        add(i, i + n);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        string girl, boy;
        cin >> girl >> boy;
        add(_map[boy], _map[girl]);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (color[i] == color[i + n]) printf("Unsafe\n");
        else printf("Safe\n");
    }
    return 0;
}