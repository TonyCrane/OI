/*************************************************************
 *  > File Name        : P1038.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/22 12:59:04
 *  > Algorithm        : Graph
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

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

int n, m, c[maxn];
bool vis[maxn], out[maxn];
queue<int> q;

struct Ans {
    int id, val;
}ans[maxn]; int ansi;
bool cmp(Ans a, Ans b) {
    return a.id < b.id;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        c[i] = read(); int x = read();
        if (c[i]) {
            q.push(i);
            vis[i] = true;
        } else {
            c[i] -= x;
            vis[i] = false;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        out[u] = true;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (c[e.from] <= 0) continue;
            c[e.to] += e.val * c[u];
            if (!vis[e.to]) {
                q.push(e.to);
                vis[e.to] = true;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] > 0 && !out[i]) {
            ans[++ansi].id = i;
            ans[ansi].val  = c[i];
        }
    }
    if (ansi == 0) {
        printf("NULL\n");
        return 0;
    }
    sort(ans + 1, ans + 1 + ansi, cmp);
    for (int i = 1; i <= ansi; ++i) {
        printf("%d %d\n", ans[i].id, ans[i].val);
    }
    return 0;
}