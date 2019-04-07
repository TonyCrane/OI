/*************************************************************
 *  > File Name        : P2176.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月22日 星期二 15时51分24秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int maxm = 5010;

struct Edge
{
	int to, nxt, l;
}edge[maxm << 1];
int head[maxn], cnt;
void add(int a, int b, int l)
{
	edge[cnt].to = b;
	edge[cnt].nxt  = head[a];
	edge[cnt].l    = l;
	head[a]        = cnt;
	cnt++;
}

int n, m, ai, bi, li, dx[maxm], dy[maxm], ans = -1, dist[maxn], p[maxm], sum;

struct heap
{
	int u, d;
	bool operator < (const heap& a) const
	{
		return d < a.d;
	}
};

void Dijkstra()
{
	priority_queue<heap> q;
	for (int i = 0; i <= n; ++i) dist[i] = INT_MAX;
	dist[1] = 0;
	q.push((heap){1, 0});
	while (!q.empty())
	{
		heap top = q.top(); q.pop();
		int tx = top.u;
		int td = top.d;
		if (td != dist[tx]) continue;
		for (int i = head[tx]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dist[v] > dist[tx] + edge[i].l)
			{
				dist[v] = dist[tx] + edge[i].l;
				dy[v] = i;
				dx[v] = tx;
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
		scanf("%d %d %d", &ai, &bi, &li);
		add(ai, bi, li);
		add(bi, ai, li);
	}
	Dijkstra();
	int old = dist[n];
	int q = n;
	while (q != 1)
	{
		p[++sum] = dy[q];
		q = dx[q];
	}
	for (int i = 1; i <= sum; ++i)
	{
		edge[p[i]].l     *= 2;
		edge[p[i] ^ 1].l *= 2;
		Dijkstra();
		ans = max(ans, dist[n]);
		edge[p[i]].l     /= 2;
		edge[p[i] ^ 1].l /= 2;
	}
//	printf("%d %d\n", ans, old);
	printf("%d\n", ans - old);
	return 0;
}
