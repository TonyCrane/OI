/*************************************************************
 *  > File Name        : P3366.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月21日 星期五 19时56分38秒
**************************************************************/

/* Prim */
#include<bits/stdc++.h>
using namespace std;

int n, m, ans, _map[5050][5050], dist[5050], pre[5050];
bool p[5050];
const int INF = 1e9;

void Prim()
{
	int k, min;
	dist[1] = 0; p[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		p[i] = false;
		dist[i] = _map[1][i];
		pre[i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		min = INF;
		k = 0;
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
			if (!p[j] && _map[k][j] != INF && dist[j] > _map[k][j])
			{
				dist[j] = _map[k][j];
				pre[j] = k;
			}
		}
	}
	return;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			_map[i][j] = INF;
	for (int i = 1; i <= n; ++i) _map[i][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (_map[x][y] >= z)
		{
			_map[x][y] = z;
			_map[y][x] = z;
		}
	}
	Prim();
	for (int i = 1; i <= n; ++i)
		ans += dist[i];
	printf("%d\n", ans);
    return 0;
}
