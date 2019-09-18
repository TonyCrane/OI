/*************************************************************
 *  > File Name        : P3007.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/18 21:21:30
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

int dfn[maxn], low[maxn], c[maxn];
int n, m, num, cnt;
stack<int> s; 
bool ins[maxn], vis[maxn];
char ans[maxn];

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

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (!vis[e.to]) {
            dfs(e.to);
        }
    }
}

bool check(int u) {
    memset(vis, 0, sizeof(vis));
    dfs(u);
    for (int i = 1; i <= n; ++i) {
        if (vis[i] && vis[i + n]) return false;
    }
    return true;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int x = read();
        char ch1[5]; scanf("%s", ch1);
        int y = read();
        char ch2[5]; scanf("%s", ch2);
        if (ch1[0] == 'Y' && ch2[0] == 'Y') {
            add(x + n, y);
            add(y + n, x);
        } else if (ch1[0] == 'Y' && ch2[0] == 'N') {
            add(x + n, y + n);
            add(y, x);
        } else if (ch1[0] == 'N' && ch2[0] == 'Y') {
            add(y + n, x + n);
            add(x, y);
        } else if (ch1[0] == 'N' && ch2[0] == 'N') {
            add(x, y + n);
            add(y, x + n);
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] == c[i + n]) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        bool p = check(i), q = check(i + n);
        if (p && q) ans[i] = '?';
        else if (!p && q) ans[i] = 'N';
        else if (p && !q) ans[i] = 'Y';
    }
    for (int i = 1; i <= n; ++i) {
        printf("%c", ans[i]);
    }
    return 0;
}