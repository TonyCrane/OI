/*************************************************************
 *  > File Name        : P2754.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/14 15:43:54
 *  > Algorithm        : Dinic
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5010;
const int inf  = 0x3f3f3f3f;

int n, m, s, t, d[maxn], ans, cur[maxn];
int ufs[25];

int find(int x) {
    return (ufs[x] == x) ? x : ufs[x] = find(ufs[x]);
}
void unionn(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) ufs[fx] = fy;
}

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

int S[25][25];

int main() {
    n = read(); m = read(); int k = read();
    s = 0; t = n + 1;
    for (int i = 1; i <= n + 1; ++i) ufs[i] = i;
    for (int i = 1; i <= m; ++i) {
        S[0][i] = read(); S[i][0] = read();
        for (int j = 1; j <= S[i][0]; ++j) {
            S[i][j] = read();
            if (S[i][j] == -1) S[i][j] = n + 1;
            if (j > 1) unionn(S[i][j], S[i][j - 1]);
        }
    }
    if (find(s) != find(t)) {
        printf("0\n");
        return 0;
    }
    for (int time = 1; ; ++time) {
        for (int i = 0; i <= n; ++i) {
            add(i + (time - 1) * (n + 2), i + time * (n + 2), inf);
        }
        add(n + 1 + time * (n + 2), n + 1 + (time - 1) * (n + 2), inf);
        for (int i = 1; i <= m; ++i) {
            int tmp = (time - 1) % S[i][0] + 1;
            add(S[i][tmp] + (time - 1) * (n + 2), S[i][time % S[i][0] + 1] + time * (n + 2), S[0][i]);
        }
        ans += dinic(s, t);
        if (ans >= k) {
            printf("%d\n", time);
            return 0;
        }
    }
}