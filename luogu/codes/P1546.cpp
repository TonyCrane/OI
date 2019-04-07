/*************************************************************
 *  > File Name        : P1546.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月06日 星期日 12时29分11秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;

int n, G[maxn][maxn], ans, dis[maxn], pre[maxn];
bool p[maxn];

void Prim()
{
	int k, minx;
	dis[1] = 0; p[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		p[i] = false;
		dis[i] = G[1][i];
		pre[i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		minx = INT_MAX;
		k = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (!p[j] && dis[j] < minx)
			{
				minx = dis[j];
				k = j;
			}
		}
		if (k == 0) return;
		p[k] = true;
		for (int j = 1; j <= n; ++j)
		{
			if (!p[j] && G[k][j] != INT_MAX && dis[j] > G[k][j])
			{
				dis[j] = G[k][j];
				pre[j] = k;
			}
		}
	}
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &G[i][j]);
		}
	}
	Prim();
	for (int i = 1; i <= n; ++i)
	{
		ans += dis[i];
	}
	printf("%d\n", ans);
	return 0;
}
