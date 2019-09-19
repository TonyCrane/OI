/*************************************************************
 *  > File Name        : SP16185.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 21:40:13
 *  > Algorithm        : tarjan-cut
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 50010;

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

int dfn[maxn], low[maxn], color[maxn];
long long cnt, n, m, num, root, notcut, cutnum, ans1, ans2;
bool cut[maxn];

void init() {
    edges.clear();
    for (int i = 0; i < maxn; ++i) {
        G[i].clear();
    }
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(color, 0, sizeof(color));
    memset(cut, 0, sizeof(cut));
    cnt = notcut = cutnum = 0;
    ans1 = 0; ans2 = 1;
    n = num = 0;
}

void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++num;
    int flag = 0;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (!dfn[e.to]) {
            tarjan(e.to, x);
            low[x] = min(low[x], low[e.to]);
            if (low[e.to] >= dfn[x]) {
                flag++;
                if (x != root || flag > 1) cut[x] = true;
            }
        } else if (e.to != fa) {
            low[x] = min(low[x], dfn[e.to]);
        }
    }
}

void dfs(int u) {
    color[u] = cnt; notcut++;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (cut[e.to] && color[e.to] != cnt) {
            cutnum++;
            color[e.to] = cnt;
        }
        if (!color[e.to]) {
            dfs(e.to);
        }
    }
}

int main() {
    int kase = 1;
    while (cin >> m && m) {
        init();
        for (int i = 1; i <= m; ++i) {
            long long u = read(), v = read();
            add(u, v);
            n = max(n, max(u, v));
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i, 0);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!color[i] && !cut[i]) {
                ++cnt;
                cutnum = notcut = 0;
                dfs(i);
                if (!cutnum) {
                    ans1 += 2;
                    ans2 *= (notcut - 1) * notcut / 2;
                } else if (cutnum == 1) {
                    ans1 += 1;
                    ans2 *= notcut;
                }
            }
        }
        printf("Case %d: %lld %lld\n", kase++, ans1, ans2);
    }
    return 0;
}