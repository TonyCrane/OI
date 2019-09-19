/*************************************************************
 *  > File Name        : P1345.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 20:58:41
 *  > Algorithm        : maxflow
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

int n, m, s, t, d[maxn], cur[maxn];
struct Edge {
    int from, to, cap, flow;
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int from, int to, int cap) {
    edges.push_back((Edge) {from, to, cap, 0});
    edges.push_back((Edge) {to, from, 0, 0});
    int mm = edges.size();
    G[from].push_back(mm - 2);
    G[to].push_back(mm - 1);
}
bool vis[maxn];
bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!vis[e.to] && e.cap > e.flow) {
                vis[e.to] = 1;
                d[e.to] = d[x] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}
int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[G[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0) break;
        }
    }
    return flow;
}
int MaxFlow(int s, int t) {
    int flow = 0;
    while (BFS()) {
        memset(cur, 0, sizeof(cur));
        flow += DFS(s, inf);
    }
    return flow;
}

int main() {
    n = read(), m = read(), s = read() + n, t = read();
    for (int i = 1; i <= n; ++i) {
        add(i, i + n, 1);
        add(i + n, i, 0);
    }
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        add(y + n, x, inf);
        add(x, y + n, 0);
        add(x + n, y, inf);
        add(y, x + n, 0);
    }
    printf("%d\n", MaxFlow(s, t));
    return 0;
}