/*************************************************************
 *  > File Name        : P4779.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月25日 星期五 16时05分28秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
const int maxm = 200010;
const int inf  = 0x3f3f3f3f;

int n, m, dis[maxn];

struct Edge
{
	int to, nxt, w;
}edge[maxm << 1];
int head[maxn], cnt;
void add(int u, int v, int w)
{
	edge[++cnt].to = v;
	edge[cnt].nxt  = head[u];
	edge[cnt].w    = w;
	head[u]        = cnt;
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
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[1] = 0;
	q.push((heap){1, 0});
	while (!q.empty())
	{
		heap top = q.top();
		q.pop();
		int tx = top.u;
		int td = top.d;
		if (td != dis[tx]) continue;
		for (int i = head[tx]; i; i = edge[i].nxt)
		{
			int v = edge[i].to;
			if (dis[v] > dis[tx] + edge[i].w)
			{
				dis[v] = dis[tx] + edge[i].w;
				q.push((heap){v, dis[v]});
			}
		}
	}
}

int main()
{
	scanf("%d %d 1", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		add(from, to, val);
	}
	Dijkstra();
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", dis[i]);
	}
	return 0;
}
