/*************************************************************
 *  > File Name        : P3119.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/29 16:43:27
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

const int maxn = 100010;

vector<int> G[maxn];
vector<int> G1[maxn];
vector<int> G2[maxn];

int n, m;
int low[maxn], dfn[maxn], dfnc, color[maxn];
int num[maxn], dis1[maxn], dis2[maxn];
stack<int> s; bool ins[maxn], vis[maxn];
vector<int> scc[maxn]; int cnt = 0;

void Tarjan(int x) {
    low[x] = dfn[x] = ++dfnc;
    s.push(x); ins[x] = true;
    for (int i = 0; i < G[x].size(); ++i) {
        int& v = G[x][i];
        if (!dfn[v]) {
            Tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (ins[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (low[x] == dfn[x]) {
        cnt++; int y;
        do {
            y = s.top(); s.pop(); ins[y] = false;
            color[y] = cnt; scc[cnt].push_back(y);
            num[cnt]++;
        } while (x != y);
    }
}

struct heap {
    int u, d;
    bool operator < (const heap& a) const {
        return d < a.d;
    }
};

void Dijkstra1(int s) {
    priority_queue<heap> q;
    dis1[s] = num[s];
    q.push((heap){s, num[s]});
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != dis1[u]) continue;
        for (int i = 0; i < G1[u].size(); ++i) {
            int& v = G1[u][i];
            if (dis1[v] < dis1[u] + num[v]) {
                dis1[v] = dis1[u] + num[v];
                q.push((heap){v, dis1[v]});
            }
        }
    }
}

void Dijkstra2(int s) {
    priority_queue<heap> q;
    dis2[s] = num[s];
    q.push((heap){s, num[s]});
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != dis2[u]) continue;
        for (int i = 0; i < G2[u].size(); ++i) {
            int& v = G2[u][i];
            if (dis2[v] < dis2[u] + num[v]) {
                dis2[v] = dis2[u] + num[v];
                q.push((heap){v, dis2[v]});
            }
        }
    }
}

void SPFA(int s) {
    dis2[s] = num[s]; vis[s] = true;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G2[u].size(); ++i) {
            int& v = G2[u][i];
            if (dis2[v] < dis2[u] + num[v]) {
                dis2[v] = dis2[u] + num[v];
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) Tarjan(i);
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i < G[u].size(); ++i) {
            int& v = G[u][i];
            if (color[u] == color[v]) continue;
            G1[color[u]].push_back(color[v]);
            G2[color[v]].push_back(color[u]);
        }
    }
    Dijkstra1(color[1]); Dijkstra2(color[1]);
    int ans = num[color[1]];
    for (int i = 1; i <= n; ++i) {
        if (!vis[color[i]] && dis1[color[i]]) {
            vis[color[i]] = true;
            for (int j = 0; j < G2[color[i]].size(); ++j) {
                int& v = G2[color[i]][j];
                if (!dis2[v]) continue;
                ans = max(ans, dis1[color[i]] + dis2[v] - num[color[1]]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}