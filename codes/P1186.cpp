/*************************************************************
 *  > File Name        : P1186.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月23日 星期三 16时59分55秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxm = maxn * (maxn - 1) / 2;
const int INF = 0xfffffff;

int n, m, ai, bi, ti, dx[maxm], dy[maxm], ans = -1, dist[maxn], p[maxm], sum;
int tmp, tnp;

struct Edge
{
	int to, nxt, t;
}edge[maxm << 1];
int head[maxn], cnt;
void add(int a, int b, int t)
{
	edge[++cnt].to  = b;
	edge[cnt].nxt = head[a];
	edge[cnt].t   = t;
	head[a]       = cnt;
}

struct heap
{
	int u, d;
	bool operator < (const heap& a) const
	{
		return d > a.d;
	}
};

void Dijkstra()
{
	priority_queue<heap> q;
	for (int i = 0; i <= n; ++i) dist[i] = INF;
	dist[1] = 0;
	q.push((heap){1, 0});
	while (!q.empty())
	{
		heap top = q.top();
		q.pop();
		int tx = top.u;
		int td = top.d;
		if (td != dist[tx]) continue;
		for (int i = head[tx]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dist[v] > dist[tx] + edge[i].t)
			{
				dist[v] = dist[tx] + edge[i].t;
				dy[v] = i;
				dx[v] = tx;
				q.push((heap){v, dist[v]});
			}
		}
	}
}

void dijkstra()
{
	priority_queue<heap> q;
	for (int i = 0; i <= n; ++i) dist[i] = INF;
	dist[1] = 0;
	q.push((heap){1, 0});
	while (!q.empty())
	{
		heap top = q.top();
		q.pop();
		int tx = top.u;
		int td = top.d;
		if (td != dist[tx]) continue;
		for (int i = head[tx]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dist[v] > dist[tx] + edge[i].t)
			{
				dist[v] = dist[tx] + edge[i].t;
				q.push((heap){v, dist[v]});
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &ai, &bi, &ti);
		add(ai, bi, ti);
		add(bi, ai, ti);
	}
	int q = n;
	ans = -1;
	Dijkstra();
	while (q != 1)
	{
		p[++sum] = dy[q];
		q = dx[q];
	}
	for (int i = 1; i <= sum; ++i)
	{
		tmp = edge[p[i]].t;
		tnp = edge[p[i] ^ 1].t;
		edge[p[i]].t     = INF;
		edge[p[i] ^ 1].t = INF;
		dijkstra();
		ans = max(ans, dist[n]);
		edge[p[i]].t     = tmp;
		edge[p[i] ^ 1].t = tnp;
	}
	printf("%d\n", ans);
	return 0;
}
