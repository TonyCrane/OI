/*************************************************************
 *  > File Name        : P1195.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月22日 星期二 11时36分04秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, m, k, xi, yi, zi, ufs[10010], ans, num;

struct Cloud
{
	int x, y, l;
}edge[10010];

void add(int x, int y, int z)
{
	edge[++num].x = x;
	edge[num].y   = y;
	edge[num].l   = z;
}

int find(int x)
{
	if (x != ufs[x]) return ufs[x] = find(ufs[x]);
	return ufs[x] = x;
}

void unionn(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
		ufs[fx] = fy;
}

bool cmp(Cloud a, Cloud b)
{
	return a.l < b.l;
}

void Kruskal()
{
	for (int i = 1; i <= n; ++i)
		ufs[i] = i;
	int num = n, x, y;
	sort(edge + 1, edge + 1 + m, cmp);
	for (int i = 1; i <= m; ++i)
	{
		if (find(edge[i].x) != find(edge[i].y))
		{
			unionn(edge[i].x, edge[i].y);
			num--;
			ans += edge[i].l;
		}
		if (num == k) break;
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if (k > n)
	{
		printf("No Answer\n");
		return 0;
	}
	if (n == k)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &xi, &yi, &zi);
		add(xi, yi, zi);
	}
	Kruskal();
	printf("%d\n", ans);
	return 0;
}
