/*************************************************************
 *  > File Name        : P4013.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/23 08:40:03
 *  > Algorithm        : 最大费用最大流
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
const int ninf = 0xc0c0c0c0;

int n, m, s, t, ansflow;
int vis[maxn], d[maxn], p[maxn], a[maxn];
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
	d[s] = 0; vis[s] = 1; p[s] = 0; a[s] = inf;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vis[x] = 0;
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (e.cap > e.flow && d[e.to] < d[x] + e.cost) {
				d[e.to] = d[x] + e.cost;
				p[e.to] = G[x][i];
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
	for (int u = t; u != s; u = edges[p[u]].from) {
		edges[p[u]].flow += a[t];
		edges[p[u] ^ 1].flow -= a[t];
	}
	return true;
}

int MaxCostMaxFlow(long long& cost) {
	int flow = 0; cost = 0;
	while (BellmanFord(flow, cost));
	return flow;
}

int in[45][45];
int point[45][45], cnt;

int main() {
    m = read(); n = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m + i - 1; ++j) {
            in[i][j] = read();
            point[i][j] = ++cnt;
        }
    }

    // Question 1
    s = 0; t = cnt * 2 + 1;
    for (int i = 1; i <= m; ++i) add(s, point[1][i], 1, 0);
    for (int i = 1; i <= n + m - 1; ++i) add(point[n][i] + cnt, t, 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (i < n) for (int j = 1; j <= m + i - 1; ++j) {
            add(point[i][j] + cnt, point[i + 1][j], 1, 0);
            add(point[i][j] + cnt, point[i + 1][j + 1], 1, 0);
        }
        for (int j = 1; j <= m + i - 1; ++j) 
            add(point[i][j], point[i][j] + cnt, 1, in[i][j]);
    }
    ansflow = MaxCostMaxFlow(anscost);
    printf("%lld\n", anscost);

    // Question 2
    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
    s = 0; t = cnt + 1;
    for (int i = 1; i <= m; ++i) add(s, point[1][i], 1, 0);
    for (int i = 1; i <= n + m - 1; ++i) add(point[n][i], t, inf, in[n][i]);
    for (int i = 1; i < n; ++i) for (int j = 1; j <= m + i - 1; ++j) {
        add(point[i][j], point[i + 1][j], 1, in[i][j]);
        add(point[i][j], point[i + 1][j + 1], 1, in[i][j]);
    }
    ansflow = MaxCostMaxFlow(anscost);
    printf("%lld\n", anscost);

    // Question 3
    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
    s = 0; t = cnt + 1;
    for (int i = 1; i <= m; ++i) add(s, point[1][i], 1, 0);
    for (int i = 1; i <= n + m - 1; ++i) add(point[n][i], t, inf, in[n][i]);
    for (int i = 1; i < n; ++i) for (int j = 1; j <= m + i - 1; ++j) {
        add(point[i][j], point[i + 1][j], inf, in[i][j]);
        add(point[i][j], point[i + 1][j + 1], inf, in[i][j]);
    }
    ansflow = MaxCostMaxFlow(anscost);
    printf("%lld\n", anscost);

    return 0;
}