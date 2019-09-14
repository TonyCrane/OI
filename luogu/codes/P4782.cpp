/*************************************************************
 *  > File Name        : P4782.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/14 14:25:57
 *  > Algorithm        : 2-SAT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2000010;

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

int dfn[maxn], low[maxn], c[maxn];
int n, m, num, cnt;
stack<int> s; bool ins[maxn];

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
            c[y] = cnt;
        } while (x != y);
    }
}

int main() {
    n = read(); m = read();
    for (int k = 1; k <= m; ++k) {
        int i = read(), a = read(), j = read(), b = read();
        int nota = a ^ 1, notb = b ^ 1;
        add(i + nota * n, j + b * n);
        add(j + notb * n, i + a * n);
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] == c[i + n]) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    puts("POSSIBLE");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", c[i] > c[i + n]);
    }
    return 0;
}