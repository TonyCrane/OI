/*************************************************************
 *  > File Name        : P3358.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/21 08:06:18
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

struct Interval {
    int l, r, len;
}inter[510];
int nums[1020], old[1020];

int main() {
    int n_ = read(), k = read();
    for (int i = 1; i <= n_; ++i) {
        inter[i].l = read(); inter[i].r = read();
        inter[i].len = inter[i].r - inter[i].l;
        nums[i * 2 - 1] = inter[i].l;
        nums[i * 2] = inter[i].r;
    }
    // for (int i = 1; i <= n_ * 2; ++i) {
    //     printf("%d ", nums[i]);
    // } printf("\n");
    for (int i = 1; i <= n_ * 2; ++i) old[i] = nums[i];
    sort(old + 1, old + 1 + n_ * 2);
    int len = unique(old + 1, old + 1 + n_ * 2) - old - 1;
    for (int i = 1; i <= n_ * 2; ++i) nums[i] = lower_bound(old + 1, old + 1 + len, nums[i]) - old;
    // for (int i = 1; i <= n_ * 2; ++i) {
    //     printf("%d ", nums[i]);
    // } printf("\n");
    for (int i = 1; i <= n_; ++i) {
        inter[i].l = nums[i * 2 - 1];
        inter[i].r = nums[i * 2];
    }
    s = 0; n = len + 2; t = n - 1;
    add(s, 1, k, 0);
    for (int i = 1; i <= len; ++i) {
        add(i, i + 1, inf, 0);
    }
    for (int i = 1; i <= n_; ++i) {
        add(inter[i].l, inter[i].r, 1, inter[i].len);
    }
    ansflow = MaxCostMaxFlow(anscost);
    printf("%d\n", anscost);
    return 0;
}