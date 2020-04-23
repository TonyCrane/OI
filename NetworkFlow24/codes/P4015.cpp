/*************************************************************
 *  > File Name        : P4015.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/23 10:07:26
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

const int maxn = 310;
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

bool BellmanFord(int& flow, long long& cost, int opt) {
    if (opt == 0) memset(d, 0x3f, sizeof(d));
    else memset(d, 0xc0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[s] = 0; vis[s] = 1; p[s] = 0; a[s] = inf;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vis[x] = 0;
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]]; bool judge;
            if (opt) judge = d[e.to] < d[x] + e.cost;
            else judge = d[e.to] > d[x] + e.cost;
			if (e.cap > e.flow && judge) {
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
	if (!opt && d[t] == inf) return false;
    if (opt && d[t] == ninf) return false;
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
	while (BellmanFord(flow, cost, 0));
	return flow;
}
int MaxCostMaxFlow(long long& cost) {
	int flow = 0; cost = 0;
	while (BellmanFord(flow, cost, 1));
	return flow;
}

int input1[110], input2[110], input3[110][110];

int main() {
    n = read(); m = read();
    s = 0; t = n + m + 1;

    for (int i = 1; i <= n; ++i) {
        int c = read(); input1[i] = c;
        add(s, i, c, 0);
    }
    for (int i = 1; i <= m; ++i) {
        int c = read(); input2[i] = c;
        add(i + n, t, c, 0);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int c = read(); input3[i][j] = c;
            add(i, j + n, inf, c);
        }
    }
    ansflow = MinCostMaxFlow(anscost);
    printf("%lld\n", anscost);

    edges.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) add(s, i, input1[i], 0);
    for (int i = 1; i <= m; ++i) add(i + n, t, input2[i], 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            add(i, j + n, inf, input3[i][j]);
        }
    }
    ansflow = MaxCostMaxFlow(anscost);
    printf("%lld\n", anscost);

    return 0;
}