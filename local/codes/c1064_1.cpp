/*************************************************************
 *  > File Name        : c1064_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/04 12:36:03
 *  > Algorithm        : Dijkstra
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

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

bool safe[maxn];
int n, m, k, d;
priority_queue<int> best[maxn];

struct heap {
    int u, d;
    bool operator < (const heap& a) const {
        return d > a.d;
    }
};
priority_queue<heap> q;
void Dijkstra() {
    while (!q.empty()) {
        heap top = q.top(); q.pop();
        int u = top.u, td = top.d;
        if (td != best[u].top()) continue;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (safe[e.to]) continue;
            if (best[e.to].size() > d) {
                if (td + e.val < best[e.to].top()) {
                    best[e.to].pop();
                    best[e.to].push(td + e.val);
                    q.push((heap){e.to, best[e.to].top()});
                }
            } else {
                best[e.to].push(td + e.val);
                if (best[e.to].size() > d) {
                    q.push((heap){e.to, best[e.to].top()});
                }
            }
        }
    }
}

int main() {
    n = read(); m = read(); k = read(); d = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
    }
    for (int i = 1; i <= k; ++i) {
        int v = read();
        safe[v] = true;
        best[v].push(0);
        q.push((heap){v, 0});
    }
    Dijkstra();
    if (best[1].size() > d) {
        printf("%d\n", best[1].top());
    } else {
        puts("-1");
    }
    return 0;
}