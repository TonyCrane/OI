/*************************************************************
 *  > File Name        : P1339.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月22日 星期二 12时10分40秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2600;
int n, m, ts, te, G[maxn][maxn], dist[maxn];
bool p[maxn];

void init()
{
	scanf("%d %d %d %d", &n, &m, &ts, &te);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			G[i][j] = INT_MAX;
	for (int i = 1; i <= n; ++i) G[i][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		int f, t, w;
		scanf("%d %d %d", &f, &t, &w);
		if (G[f][t] > w)
		{
			G[f][t] = w;
			G[t][f] = w;
		}
	}
}

void Dijkstra()
{
	int k, min;
	for (int i = 1; i <= n; ++i)
	{
		p[i] = false;
		if (i != ts) dist[i] = G[ts][i];
	}
	dist[ts] = 0; p[ts] = true;
	for(int i = 1; i <= n - 1; ++i)
	{
		min = INT_MAX; k = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (!p[j] && dist[j] < min)
			{
				min = dist[j];
				k = j;
			}
		}
		if (k == 0) return;
		p[k] = true;
		for (int j = 1; j <= n; ++j)
		{
			if (!p[j] && G[k][j] != INT_MAX && dist[j] > dist[k] + G[k][j])
				dist[j] = dist[k] + G[k][j];
		}
	}
	return;
}

int main()
{
	init();
	Dijkstra();
	printf("%d\n", dist[te]);
	return 0;
}
