/*************************************************************
 *  > File Name        : P4009.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/21 14:33:46
 *  > Algorithm        : 建分层图 最小费用最大流
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;
const int inf  = 0x3f3f3f3f;

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
    memset(d, 0x3f, sizeof(d));
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

int N, K, A, B, C;
int in[110][110];

int point(int x, int y, int dep) {
    return (x - 1) * N + y + dep * N * N;
}

int main() {
    N = read(); K = read(); A = read(); B = read(); C = read();
    s = 0; n = (K + 1) * N * N; t = n + 1;
    for (int i = 1; i <= N; ++i) 
        for (int j = 1; j <= N; ++j) {
            in[i][j] = read();
            if (in[i][j]) {
                for (int k = 1; k <= K; ++k) {
                    add(point(i, j, k), point(i, j, 0), 1, A);
                }
            }
            for (int k = 0; k < K; ++k) {
                if (in[i][j] && k) break;
                if (i + 1 <= N) add(point(i, j, k), point(i + 1, j, k + 1), 1, 0);
                if (j + 1 <= N) add(point(i, j, k), point(i, j + 1, k + 1), 1, 0);
                if (i - 1 >= 1) add(point(i, j, k), point(i - 1, j, k + 1), 1, B);
                if (j - 1 >= 1) add(point(i, j, k), point(i, j - 1, k + 1), 1, B);
            }
            if (!in[i][j]) add(point(i, j, K), point(i, j, 0), 1, A + C);
        }
    add(s, point(1, 1, 0), 1, 0);
    for (int k = 0; k <= K; ++k) {
        add(point(N, N, k), t, 1, 0);
    }
    ansflow = MinCostMaxFlow(anscost);
    printf("%lld\n", anscost);
    return 0;
}