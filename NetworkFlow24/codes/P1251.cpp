/*************************************************************
 *  > File Name        : P1251.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/14 10:58:33
 *  > Algorithm        : 最小费用最大流
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 4010;
const int inf  = 0x3f3f3f3f;

int n, m, s, t, ansflow, r[maxn];
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
	for (int i = 1; i <= n; ++i) d[i] = inf;
	memset(vis, 0, sizeof(vis));
	d[s] = 0; vis[s] = 1; p[s] = 0; a[s] = inf;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vis[x] = 0;
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (e.cap > e.flow && d[e.to] > d[x] + e.cost) {
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
	if (d[t] == inf) return false;
	flow += a[t];
	cost += (long long)d[t] * (long long)a[t];
	for (int u = t; u != s; u = edges[p[u]].from) {
		edges[p[u]].flow += a[t];
		edges[p[u] ^ 1].flow -= a[t];
	}
	return true;
}

int MinCostMaxFlow(long long& cost) {
	int flow = 0; cost = 0;
	while (BellmanFord(flow, cost));
	return flow;
}

int main() {
    int N = read(); s = 0; t = 2 * N + 1;
    n = t + 1;
    for (int i = 1; i <= N; ++i) {
        r[i] = read();
        add(s, i + N, r[i], 0);
        add(i, t, r[i], 0);
    }
    int pr = read(), t1 = read(), c1 = read(), t2 = read(), c2 = read();
    for (int i = 1; i <= N; ++i) {
        if (i + 1 <= N) add(i + N, i + N + 1, inf, 0);
        if (i + t1 <= N) add(i + N, i + t1, inf, c1);
        if (i + t2 <= N) add(i + N, i + t2, inf, c2);
        add(s, i, inf, pr);
    }
    MinCostMaxFlow(anscost);
    printf("%lld\n", anscost);
    return 0;
}