/*************************************************************
 *  > File Name        : P3376_ISAP.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月04日 星期四 17时05分57秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const int inf  = 0x3f3f3f3f;

int n, m, s, t;
int d[maxn], p[maxn], num[maxn], cur[maxn];
bool vis[maxn];

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int mm = edges.size();
	G[from].push_back(mm - 2);
	G[to].push_back(mm - 1);
}

void bfs() {
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	Q.push(t);
	d[t] = 0; vis[t] = 1;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (!vis[e.from] && e.cap > e.flow) {
				vis[e.from] = 1;
				d[e.from] = d[x] + 1;
				Q.push(e.from);
			}
		}
	}
}

int Augment() {
	int x = t, a = inf;
	while (x != s) {
		Edge& e = edges[p[x]];
		a = min(a, e.cap - e.flow);
		x = edges[p[x]].from;
	}
	x = t;
	while (x != s) {
		edges[p[x]].flow += a;
		edges[p[x] ^ 1].flow -= a;
		x = edges[p[x]].from;
	}
	return a;
}

int ISAP(int s, int t) {
	int flow = 0;
	bfs();
	memset(num, 0, sizeof(num));
	for (int i = 0; i < n; ++i) num[d[i]]++;
	int x = s;
	memset(cur, 0, sizeof(cur));
	while (d[s] < n) {
		if (x == t) {
			flow += Augment();
			x = s;
		}
		int ok = 0;
		for (int i = cur[x]; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (e.cap > e.flow && d[x] == d[e.to] + 1) {
				ok = 1;
				p[e.to] = G[x][i];
				cur[x] = i;
				x = e.to;
				break;
			}
		}
		if (!ok) {
			int mm = n - 1;
			for (int i = 0; i < G[x].size(); ++i) {
				Edge& e = edges[G[x][i]];
				if (e.cap > e.flow) mm = min(mm, d[e.to]);
			}
			if (--num[d[x]] == 0) break;
			num[d[x] = mm + 1]++;
			cur[x] = 0;
			if (x != s) x = edges[p[x]].from;
		}
	}
	return flow;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		add(u, v, c);
	}
	printf("%d\n", ISAP(s, t));
	return 0;
}
