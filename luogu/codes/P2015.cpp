/*************************************************************
 *  > File Name        : P2015.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年03月21日 星期四 15时16分11秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, q;
int lson[110], rson[110], a[110];
int dp[110][110], G[110][110];

void make(int root)
{
	for (int i = 1; i <= n; ++i)
	{
		if (G[root][i] != -1)
		{
			lson[root] = i;
			a[i] = G[root][i];
			G[root][i] = -1;
			G[i][root] = -1;
			make(i);
			break;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (G[root][i] != -1)
		{
			rson[root] = i;
			a[i] = G[root][i];
			G[root][i] = -1;
			G[i][root] = -1;
			make(i);
			break;
		}
	}
}

int DP(int _i, int _j)
{
	if (_j == 0) return 0;
	if (lson[_i] == 0 && rson[_i] == 0) return a[_i];
	if (dp[_i][_j] > 0) return dp[_i][_j];
	for (int i = 0; i < _j; ++i)
		dp[_i][_j] = max(dp[_i][_j], DP(lson[_i], i) + DP(rson[_i], _j - i - 1) + a[_i]);
	return dp[_i][_j];
}

int main()
{
	scanf("%d %d", &n, &q);
	q++;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			G[i][j] = -1;
	for (int i = 1; i < n; ++i)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		G[x][y] = z;
		G[y][x] = z;
	}
	make(1);
	printf("%d\n", DP(1, q));
	return 0;
}
