/*************************************************************
 *  > File Name        : codevs3052.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月19日 星期五 12时33分33秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 110 * 110;
const int inf  = 0x3f3f3f3f;

bool g[110][110], vis[maxn];
int n, m, s, t, k, d[maxn], cur[maxn];
struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
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
int Hash(int x, int y) {
	return (x - 1) * m + y;
}

bool bfs() {
	memset(vis, 0, sizeof(vis));
	queue<int> Q; Q.push(s);
	d[s] = 0; vis[s] = true;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (!vis[e.to] && e.cap > e.flow) {
				vis[e.to] = true;
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
		if (d[e.to] == d[x] + 1 && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
			e.flow += f;
			edges[G[x][i] ^ 1].flow -= f;
			flow += f;
			a -= f;
			if (a == 0) break;
		}
	}
	return flow;
}

int maxflow(int s, int t) {
	int flow = 0;
	while (bfs()) {
		memset(cur, 0, sizeof(cur));
		flow += dfs(s, inf);
	}
	return flow;
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	while (k--) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x][y] = true;
	}
	s = 0; t = n * m + 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (((i + j) & 1 ) && !g[i][j]) {
				add(s, Hash(i, j), 1);
				if (i - 1 > 0 && !g[i - 1][j]) {
					add(Hash(i, j), Hash(i - 1, j), inf);
				}
				if (i + 1 <=n && !g[i + 1][j]) {
					add(Hash(i, j), Hash(i + 1, j), inf);
				}
				if (j - 1 > 0 && !g[i][j - 1]) {
					add(Hash(i, j), Hash(i, j - 1), inf);
				}
				if (j + 1 <=m && !g[i][j + 1]) {
					add(Hash(i, j), Hash(i, j + 1), inf);
				}
			} else if (!((i + j) & 1) && !g[i][j]) {
				add(Hash(i, j), t, 1);
			}
		}
	}
	printf("%d\n", maxflow(s, t));
	return 0;
}