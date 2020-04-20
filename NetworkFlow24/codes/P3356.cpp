/*************************************************************
 *  > File Name        : P3356.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/20 14:55:29
 *  > Algorithm        : 费用流
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 4010;
const int inf  = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;

int n, m, s, t, ansflow;
int vis[maxn], d[maxn], pre[maxn], a[maxn];
long long anscost;

struct Edge {
	int from, to, cap, flow, cost;
	Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w){}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int c, int w) {
	edges.push_back(Edge(u, v, c, 0, w));
	edges.push_back(Edge(v, u, 0, 0,-w));
	int mm = edges.size();
	G[u].push_back(mm - 2);
	G[v].push_back(mm - 1);
}

bool BellmanFord(int& flow, long long& cost) {
    memset(d, 0xc0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[s] = 0; vis[s] = 1; pre[s] = 0; a[s] = inf;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vis[x] = 0;
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (e.cap > e.flow && d[e.to] < d[x] + e.cost) {
				d[e.to] = d[x] + e.cost;
				pre[e.to] = G[x][i];
				a[e.to] = min(a[x], e.cap - e.flow);
				if (!vis[e.to]) {
					Q.push(e.to);
					vis[e.to] = 1;
				}
			}
		}
	}
	if (d[t] == ninf) return false;
	flow += a[t];
	cost += (long long)d[t] * (long long)a[t];
	for (int u = t; u != s; u = edges[pre[u]].from) {
		edges[pre[u]].flow += a[t];
		edges[pre[u] ^ 1].flow -= a[t];
	}
	return true;
}

int MaxCostMaxFlow(long long& cost) {
	int flow = 0; cost = 0;
	while (BellmanFord(flow, cost));
	return flow;
}

int p, q;
int in[40][40];

int point(int x, int y) {
    return (x - 1) * p + y;
}

void dfs(int x, int y, int u, int id) {
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        Edge& ne = edges[G[u][i] ^ 1];
        if (e.to == s || e.to == t || e.to == u - n) continue;
        if (!e.flow) continue;
        e.flow--;
        if (e.to > n) {
            dfs(x, y, e.to, id);
            return;
        }
        int nx, ny, dir;
        if (e.to == point(x, y) + 1) {
            nx = x; ny = y + 1;
            dir = 1;
        } else {
            nx = x + 1; ny = y;
            dir = 0;
        }
        printf("%d %d\n", id, dir);
        dfs(nx, ny, e.to + n, id);
        return;
    }
}


int main() {
    int c = read(); p = read(); q = read();
    n = p * q; s = 0; t = 2 * n + 1;
    for (int i = 1; i <= q; ++i) {
        for (int j = 1; j <= p; ++j) {
            in[i][j] = read();
            if (in[i][j] == 0) add(point(i, j), point(i, j) + n, inf, 0);
            if (in[i][j] == 2) {
                add(point(i, j), point(i, j) + n, inf, 0);
                add(point(i, j), point(i, j) + n, 1, 1);
            }
        }
    }
    if (in[1][1] != 1) add(s, 1, c, 0);
    for (int i = 1; i <= q; ++i) {
        for (int j = 1; j <= p; ++j) {
            if (in[i][j] == 1) continue;
            if (in[i][j + 1] != 1 && j + 1 <= p) add(point(i, j) + n, point(i, j + 1), inf, 0);
            if (in[i + 1][j] != 1 && i + 1 <= q) add(point(i, j) + n, point(i + 1, j), inf, 0);
        }
    }
    if (in[q][p] != 1) add(point(q, p) + n, t, c, 0);
    ansflow = MaxCostMaxFlow(anscost);
    // printf("%d %d\n", ansflow, anscost);
    for (int i = 1; i <= ansflow; ++i) {
        dfs(1, 1, 1, i);
    }
    return 0;
}