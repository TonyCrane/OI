/*************************************************************
 *  > File Name        : P2766.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/15 14:53:42
 *  > Algorithm        : LIS+最大流
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2010;
const int inf  = 0x3f3f3f3f;

int s, t, d[maxn], cur[maxn];

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

int n, num[510], dp[510], ans1, ans2, ans3; 

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        num[i] = read();
    }

    // Question 1
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (num[j] <= num[i] && dp[j] > dp[i]) dp[i] = dp[j];
        }
        dp[i]++;
        ans1 = max(ans1, dp[i]);
    }
    printf("%d\n", ans1);

    // Question 2
    s = 0, t = 2 * n + 1;
    for (int i = 1; i <= n; ++i) if (dp[i] == 1) add(s, i, 1);
    for (int i = 1; i <= n; ++i) add(i, i + n, 1);
    for (int i = 1; i <= n; ++i) if (dp[i] == ans1) add (i + n, t, 1);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j < i; ++j) 
            if (num[j] <= num[i] && dp[i] == dp[j] + 1)
                add(j + n, i, 1);
    ans2 = dinic(s, t);
    printf("%d\n", ans2);

    // Question 3
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    add(s, 1, inf); add(1, 1 + n, inf);
    if (dp[n] == ans1) {
        add(n, n + n, inf);
        add(n + n, t, inf);
    }
    ans3 = ans2 + dinic(s, t);
    printf("%d\n", ans3);

    return 0;
}