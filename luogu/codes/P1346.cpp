/*************************************************************
 *  > File Name        : P1346.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月22日 星期二 15时42分19秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int inf = 1000000;
int G[maxn][maxn], n, m, k, f, t;

int main()
{
	scanf("%d %d %d", &n, &f, &t);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			G[i][j] = inf;
			G[i][i] = 0;
		}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &k);
		for (int j = 1; j <= k; ++j)
		{
			int a;
			scanf("%d", &a);
			if (j == 1) G[i][a] = 0;
			else G[i][a] = 1;
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
	if (G[f][t] == inf) printf("-1\n");
	else printf("%d\n", G[f][t]);
	return 0;
}
