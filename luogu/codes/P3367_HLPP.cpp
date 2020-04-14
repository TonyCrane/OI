/*************************************************************
 *  > File Name        : P3367_HLPP.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/14 09:59:52
 *  > Algorithm        : MaxFlow HLPP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 20010;
const int maxm = 200010;
const int inf  = 0x3f3f3f3f;

struct Edge {
    int from, to, cap;
    Edge(int f, int t, int c): from(f), to(t), cap(c) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int f, int t, int c) {
    edges.push_back(Edge(f, t, c));
    edges.push_back(Edge(t, f, 0));
    int mm = edges.size();
    G[t].push_back(mm - 1);
    G[f].push_back(mm - 2);
}

struct Node {
    int id, e, h;
    Node() {}
    Node(int i, int e, int h): id(i), e(e), h(h) {}
    bool operator < (const Node& a) const {
        return h < a.h;
    }
}node[maxn];
priority_queue<Node> pq;

int n, m, s, t;
int vis[maxn], gap[maxn << 1];

queue<int> q;
bool bfs() {
    for (int i = 0; i <= n; ++i)
        node[i].h = inf;
    node[t].h = 0; q.push(t);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (edges[G[u][i] ^ 1].cap && node[e.to].h > node[u].h + 1) {
                node[e.to].h = node[u].h + 1;
                q.push(e.to);
            }
        }
    }
    return node[s].h != inf;
}

void push(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if ((e.cap) && (node[e.to].h + 1 == node[u].h)) {
            int df = min(node[u].e, e.cap);
            e.cap -= df; edges[G[u][i] ^ 1].cap += df;
            node[u].e -= df; node[e.to].e += df;
            if ((e.to != s) && (e.to != t) && (!vis[e.to])) {
                pq.push(Node(e.to, node[e.to].e, node[e.to].h));
                vis[e.to] = 1;
            }
            if (!node[u].e) break;
        }
    }
}

void relabel(int u) {
    node[u].h = inf;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if ((e.cap) && (node[e.to].h + 1 < node[u].h)) node[u].h = node[e.to].h + 1;
    }
}

int HLPP() {
    if (!bfs()) return 0;
    node[s].h = n;
    memset(gap, 9, sizeof(int) * (n << 1));
    for (int i = 1; i <= n; ++i)
        if (node[i].h != inf) gap[node[i].h]++;
    for (int i = 0; i < G[s].size(); ++i) {
        Edge& e = edges[G[s][i]];
        if (int f = e.cap) {
            e.cap -= f; edges[G[s][i] ^ 1].cap += f;
            node[s].e -= f; node[e.to].e += f;
            if (e.to != s && e.to != t && !vis[e.to]) {
                pq.push(Node(e.to, node[e.to].e, node[e.to].h));
                vis[e.to] = 1;
            }
        }
    }
    while (!pq.empty()) {
        Node top = pq.top(); pq.pop(); int u = top.id;
        vis[u] = 0; push(u);
        if (node[u].e) {
            if (!--gap[node[u].h]) {
                for (int v = 1; v <= n; ++v) {
                    if (v != s && v != t && node[v].h > node[u].h && node[v].h < n + 1) {
                        node[v].h = n + 1;
                    }
                }
            }
            relabel(u); gap[node[u].h]++;
            pq.push(Node(u, node[u].e, node[u].h)); vis[u] = 1;
        }
    }
    return node[t].e;
}

int main() {
    n = read(); m = read(); s = read(); t = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    printf("%d\n", HLPP());
    return 0;
}