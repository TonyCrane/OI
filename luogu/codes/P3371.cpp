/*************************************************************
 *  > File Name        : P3371.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月05日 星期六 12时29分09秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
const int maxm = 500010;

int n, m, s, n_edge;
int dis[maxn], vis[maxn], head[maxm];
struct Edge
{
	int next, to, dis;
}edge[maxm];

void add(int from, int to, int dis)
{
	edge[++n_edge].next = head[from];
	edge[n_edge].to  = to;
	edge[n_edge].dis = dis;
	head[from]       = n_edge;
}

void SPFA()
{
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		dis[i] = INT_MAX;
		vis[i] = 0;
	}
	q.push(s);
	dis[s] = 0; vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop(); vis[u] = 0;
		for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (dis[v] > dis[u] + edge[i].dis)
			{
				dis[v] = dis[u] + edge[i].dis;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &s);
	for (int i = 1; i <= m; ++i)
	{
		int f, t, d;
		scanf("%d %d %d", &f, &t, &d);
		add(f, t, d);
	}
	SPFA();
	for (int i = 1; i <= n; ++i)
	{
		if (s == i)
		{
			printf("0 ");
		}
		else
		{
			printf("%d ", dis[i]);
		}
	}
	return 0;
}
