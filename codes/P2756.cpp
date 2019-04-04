/*************************************************************
 *  > File Name        : P2756.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月03日 星期三 16时58分04秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 120;
const int inf = 0x3f3f3f3f;

int n, m, s, t;
int d[maxn], cur[maxn];

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){};
};
vector<Edge> edges;
vector<int> G[maxn];

void add(int u, int v, int c) {
	edges.push_back(Edge(u, v, c, 0));
	edges.push_back(Edge(v, u, 0, 0));
	int mm = edges.size();
	G[u].push_back(mm - 2);
	G[v].push_back(mm - 1);
}

bool vis[maxn];
bool bfs() {
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

int dfs(int x, int a) {
	if (x == t || a == 0) return a;
	int flow = 0, f;
	for (int& i = cur[x]; i < G[x].size(); ++i) {
		Edge& e = edges[G[x][i]];
		if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
			e.flow += f;
			edges[G[x][i] ^ 1].flow -= f;
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int MaxFlow(int s, int t) {
	int flow = 0;
	while (bfs()) {
		memset(cur, 0, sizeof(cur));
		flow += dfs(s, inf);
	}
	return flow;
}

int main() {
	scanf("%d %d", &m, &n);
	s = 0; t = n + 1;
	int u, v;
	while (scanf("%d %d", &u, &v) == 2 && u != -1 && v != -1) {
		add(u, v, 1);
	}
	for (int i = 1; i <= m; ++i) {
		add(s, i, 1);
	}
	for (int i = m + 1; i <= n; ++i) {
		add(i, t, 1);
	}
	int flow = MaxFlow(s, t);
	if (flow == 0) {
		printf("No Solution!\n");
		return 0;
	}
	printf("%d\n", flow);
	for (int i = 0; i < edges.size(); i = i + 2) {
		if (edges[i].from != s && edges[i].to != t) {
			if (edges[i].flow != 0) {
				printf("%d %d\n", edges[i].from, edges[i].to);
			}
		}
	}
	return 0;
}
