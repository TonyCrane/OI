/*************************************************************
 *  > File Name        : P3385.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/14 21:02:32
 *  > Algorithm        : 
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

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int n, m;
int dis[maxn], cnt[maxn];
bool vis[maxn];

bool SPFA(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    queue<int> q;
    q.push(s); dis[s] = 0; vis[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop(); vis[u] = false;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (dis[e.to] > dis[u] + e.val) {
                dis[e.to] = dis[u] + e.val;
                if (!vis[e.to]) {
                    vis[e.to] = true;
                    q.push(e.to);
                    cnt[e.to]++;
                }
                if (cnt[e.to] >= n) return true;
            }
        }
    }
    return false;
}


int main() {
    int T = read();
    while (T--) {
        edges.clear();
        for (int i = 0; i < 2010; ++i) G[i].clear();
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read(), w = read();
            add(u, v, w);
            if (w >= 0) add(v, u, w);
        }
        if (SPFA(1)) printf("YE5\n");
        else printf("N0\n");
    }
    return 0;
}