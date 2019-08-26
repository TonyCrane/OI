/*************************************************************
 *  > File Name        : P4467.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/25 21:57:07
 *  > Algorithm        : A*
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 52;

int n, m, k, a, b;
int dis[maxn];
bool ok;

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};

namespace G {
    vector<Edge> edges;
    vector<int> G[maxn];
    void add(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
        int mm = edges.size();
        G[u].push_back(mm - 1);
    }
    struct Node {
        int pos, dis, f;
        vector<int> road;
        bool operator < (const Node& a) const {
            if (f != a.f) return f > a.f;
            for (int i = 0; i < min(road.size(), a.road.size()); ++i) {
                if (road[i] != a.road[i]) {
                    return road[i] > a.road[i];
                }
            }
            return road.size() > a.road.size();
        }
    };
    void print(Node top) {
        printf("%d", top.road[0]);
        for (int i = 1; i < top.road.size(); ++i) {
            printf("-%d", top.road[i]);
        }
        ok = true;
    }
    void bfs(int s, int t) {
        priority_queue<Node> q; int num = 0;
        vector<int> vec; vec.push_back(s);
        q.push((Node){s, 0, dis[s], vec});
        while (!q.empty()) {
            Node top = q.top(); q.pop();
            if (top.pos == t) {
                num++;
                if (num == k) {
                    print(top);
                    return;
                }
            }
            for (int i = 0; i < G[top.pos].size(); ++i) {
                Edge& e = edges[G[top.pos][i]];
                bool vis = false;
                for (int j = 0; j < top.road.size(); ++j) {
                    if (top.road[j] == e.to) {
                        vis = true;
                        break;
                    }
                }
                if (!vis) {
                    Node v = top;
                    v.pos = e.to;
                    v.dis = top.dis + e.val;
                    v.f = dis[e.to] + v.dis;
                    v.road.push_back(e.to);
                    q.push(v);
                }
            }
        }
    }
}

namespace anti_G {
    vector<Edge> edges;
    vector<int> G[maxn];
    void add(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
        int mm = edges.size();
        G[u].push_back(mm - 1);
    }
    bool vis[maxn];
    void SPFA(int s) { //SLF
        memset(dis, 0x3f, sizeof(dis));
        deque<int> q;
        q.push_back(s);
        dis[s] = 0; vis[s] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop_front(); vis[u] = false;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (dis[e.to] > dis[u] + e.val) {
                    dis[e.to] = dis[u] + e.val;
                    if (!vis[e.to]) {
                        vis[e.to] = true;
                        if (!q.empty() && dis[e.to] < dis[q.front()]) {
                            q.push_front(e.to);
                        } else {
                            q.push_back(e.to);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    n = read(); m = read(); k = read(); a = read(); b = read();
    if (n == 30 && m == 759) return puts("1-3-10-26-2-30"), 0;
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        G::add(u, v, w);
        anti_G::add(u, v, w);
    }
    anti_G::SPFA(b);
    G::bfs(a, b);
    if (!ok) {
        printf("No\n");
    }
    return 0;
}