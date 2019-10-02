/*************************************************************
 *  > File Name        : P3469.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/02 15:22:13
 *  > Algorithm        : Tarjan-cut
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

int dfn[maxn], low[maxn], n, m, num, root;
bool cut[maxn];
long long siz[maxn], ans[maxn];

void tarjan(int x) {
    dfn[x] = low[x] = ++num;
    int flag = 0; long long cnt = 0; siz[x] = 1LL;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            tarjan(e.to);
            siz[x] += siz[e.to];
            low[x] = min(low[x], low[e.to]);
            if (low[e.to] >= dfn[x]) {
                flag++; cnt += siz[e.to];
                ans[x] += (long long)siz[e.to] * (n - siz[e.to]);
                if (x != root || flag > 1) cut[x] = true;
            }
        } else {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
    if (!cut[x]) {
        ans[x] = (long long)2 * (n - 1);
    } else {
        ans[x] += (long long)(n - cnt - 1) * (cnt + 1) + (long long)n - 1LL;
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            root = i;
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}