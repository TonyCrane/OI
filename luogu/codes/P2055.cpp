/*************************************************************
 *  > File Name        : P2055.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/16 16:09:08
 *  > Algorithm        : maxflow
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 210;

int n, m, s, t, d[maxn], cur[maxn];
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
	queue<int> q;
	q.push(s);
	d[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (!vis[e.to] && e.cap > e.flow) {
				vis[e.to] = 1;
				d[e.to] = d[x] + 1;
				q.push(e.to);
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

int MaxFlow(int s, int t) {
	int flow = 0;
	while (BFS()) {
		memset(cur, 0, sizeof(cur));
		flow += DFS(s, 0x3f3f3f3f);
	}
	return flow;
}

int main() {
	int T = read();
	while (T--) {
		edges.clear();
		for (int i = 0; i < maxn; ++i) {
			G[i].clear();
		}
		bool zx[maxn], hj[maxn];
		int cnt = 0;
		n = read(); s = 0, t = 2 * n + 1;
		for (int i = 1; i <= n; ++i) {
			zx[i] = (bool)read();
			if (zx[i]) {
				add(i + n, t, 1);
			}
		}
		for (int i = 1; i <= n; ++i) {
			hj[i] = (bool)read();
			if (zx[i] && !hj[i] || !zx[i]) {
				add(s, i, 1);
				cnt++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				bool x = (bool)read();
				if (x || i == j) {
					add(i, j + n, 1);
				}
			}
		}
		if (MaxFlow(s, t) >= cnt) {
			printf("^_^\n");
		} else {
			printf("T_T\n");
		}
	}
	return 0;
}