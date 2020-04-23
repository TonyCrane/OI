/*************************************************************
 *  > File Name        : P2775.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/23 11:33:57
 *  > Algorithm        : IDA*
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;
const int inf  = 0x3f3f3f3f;

struct Edge {
    int from, to;
    Edge(int f, int t): from(f), to(t) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int f, int t) {
    edges.push_back(Edge(f, t));
    int mm = edges.size();
    G[f].push_back(mm - 1);
}

int n, s, t, num, pos, need, maxdep;
int dis[maxn], dist[maxn][maxn], pre[maxn], state[maxn], valid[maxn];
bool vis[maxn], onpath[maxn];

void SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0; vis[s] = true;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + 1) {
                dis[e.to] = dis[u] + 1;
                pre[e.to] = u;
                if (!vis[e.to]) {
                    q.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
}

bool dfs(int depth) {
    if (state[t] == -1) return true;
    if (depth + dist[pos][t] + need > maxdep) return false;
    for (int id = 1; id <= num; ++id) {
        int u = valid[id];
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (state[e.to] == 1) {
                if (!onpath[e.to] &&  onpath[u] && state[u] != -1) need--;
                if ( onpath[e.to] && !onpath[u] && state[u] != -1) need++;
                valid[id] = e.to;
                if (pos == u) pos = e.to;
                swap(state[u], state[e.to]);
                if (dfs(depth + 1)) return true;
                if (!onpath[e.to] &&  onpath[u] && state[e.to] != -1) need++;
                if ( onpath[e.to] && !onpath[u] && state[e.to] != -1) need--;
                valid[id] = u;
                if (pos == e.to) pos = u;
                swap(state[u], state[e.to]);
            }
        }
    }
    return false;
}

int main() {
    n = read(); s = read(); t = read();
    pos = s; valid[++num] = s; state[s] = -1;
    for (int i = 0; i < n; ++i) {
        state[i] = read(); int k = read();
        if (!state[i]) valid[++num] = i;
        for (int j = 1; j <= k; ++j) {
            int v = read();
            add(i, v);
        }
    }
    state[s] = -1;
    for (int i = 0; i < n; ++i) {
        SPFA(i);
        for (int j = 0; j < n; ++j) dist[i][j] = dis[j];
        if (i == s) {
            int u = t; onpath[u] = true;
            while (u != s) {
                if (!state[u]) need++;
                u = pre[u];
                onpath[u] = true;
            }
        }
    }
    for (maxdep = 1; maxdep <= 22; ++maxdep) {
        if (dfs(0)) {
            printf("%d\n", maxdep);
            return 0;
        }
    }
}