/*************************************************************
 *  > File Name        : P3376.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月03日 星期三 12时45分06秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

int n, m, s, t, ans;

struct Edge {
	int from, to, cap, flow;
	Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
};

vector<Edge> edges;
vector<int> G[maxn];
int a[maxn], p[maxn];

void add(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int mm = edges.size();
	G[from].push_back(mm - 2);
	G[to].push_back(mm - 1);
}

void EdmondsKarp() {
	ans = 0;
	for (;;) {
		memset(a, 0, sizeof(a));
		queue<int> Q;
		Q.push(s);
		a[s] = 0x3f3f3f3f;
		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			for (int i = 0; i < G[x].size(); ++i) {
				Edge& e = edges[G[x][i]];
				if (!a[e.to] && e.cap > e.flow) {
					p[e.to] = G[x][i];
					a[e.to] = min(a[x], e.cap - e.flow);
					Q.push(e.to);
				}
			}
			if (a[t]) break;
		}
		if (!a[t]) break;
		for (int u = t; u != s; u = edges[p[u]].from) {
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
		}
		ans += a[t];
	}
	return;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < n; ++i) {
		G[i].clear();
	}
	edges.clear();
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
//	for(int i=0;i<edges.size();i++)
//	{
//		Edge & e=edges[i];
//		cout<<e.from<<' '<<e.to<<' '<<e.cap<<' '<<e.flow<<endl;
//	}
	EdmondsKarp();
	printf("%d\n", ans);
	return 0;
}
