/*************************************************************
 *  > File Name        : P2774.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/16 09:43:15
 *  > Algorithm        : 最大流
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
const int inf  = 0x3f3f3f3f;
const int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, s, t, d[maxn], cur[maxn], tot;

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

int dinic(int s, int t) {
    int flow = 0;
    while (BFS()) {
        memset(cur, 0, sizeof(cur));
        flow += DFS(s, inf);
    }
    return flow;
}

int point(int x, int y) {
    return (x - 1) * n + y;
}

int main() {
    m = read(); n = read();
    s = 0; t = n * m + 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int a = read(); tot += a;
            if ((i + j) % 2 == 0) {
                add(s, point(i, j), a);
                for (int k = 0; k < 4; ++k) {
                    int nx = i + go[k][0];
                    int ny = j + go[k][1];
                    if (1 <= nx && nx <= m && 1 <= ny && ny <= n) {
                        add(point(i, j), point(nx, ny), inf);
                    }
                }
            } else {
                add(point(i, j), t, a);
            }
        }
    }
    int maxflow = dinic(s, t);
    printf("%d\n", tot - maxflow);
    return 0;
}