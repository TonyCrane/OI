/*************************************************************
 *  > File Name        : P3254.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/17 07:42:39
 *  > Algorithm        : 二分图最大匹配
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 450;
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

int dinic(int s, int t) {
    int flow = 0;
    while (BFS()) {
        memset(cur, 0, sizeof(cur));
        flow += DFS(s, inf);
    }
    return flow;
}

int tot;

int main() {
    m = read(); n = read();
    s = 0; t = m + n + 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            add(i, j + m, 1);
        }
    }
    for (int i = 1; i <= m; ++i) {
        int r = read(); tot += r;
        add(s, i, r);
    }
    for (int i = 1; i <= n; ++i) {
        int c = read();
        add(i + m, t, c);
    }
    int maxflow = dinic(s, t);
    if (maxflow == tot) {
        printf("1\n");
        for (int u = 1; u <= m; ++u) {
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (e.to != s && e.cap == e.flow) {
                    printf("%d ", e.to - m);
                }
            }
            printf("\n");
        }
    } else {
        printf("0\n");
    }
    return 0;
}