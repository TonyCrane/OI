/*************************************************************
 *  > File Name        : P3367.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月21日 星期五 19时28分23秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int ufs[10010];
int n, m, z, x, y;

int find(int x)
{
	if (ufs[x] != x) return ufs[x] = find(ufs[x]);
	else return x;
}

int unionn(int r1, int r2)
{
	if (find(r1) != find(r2))
		ufs[find(r2)] = find(r1);
}

int main()
{
    scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) ufs[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &z, &x, &y);
		if (z == 1)
			unionn(x, y);
		else if (z == 2)
		{
			if (find(x) == find(y))
				printf("Y\n");
			else printf("N\n");
		}
	}
    return 0;
}
