/*************************************************************
 *  > File Name        : P3388.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/01 13:46:31
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

const int maxn = 20010;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    edges.push_back(Edge(v, u));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

bool cut[maxn];
int n, m, num, root, ansi;
int dfn[maxn], low[maxn], s[maxn], ans[maxn];

void tarjan(int x) {
    dfn[x] = low[x] = ++num; int flag = 0;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            tarjan(e.to);
            low[x] = min(low[x], low[e.to]);
            if (low[e.to] >= dfn[x]) {
                flag++;
                if (x != root || flag > 1) {
                    cut[x] = true;
                }
            }
        } else {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        if (u == v) continue;
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (cut[i]) {
            ans[++ansi] = i;
        }
    }
    printf("%d\n", ansi);
    for (int i = 1; i <= ansi; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}