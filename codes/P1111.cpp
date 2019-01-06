/*************************************************************
 *  > File Name        : P1111.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月05日 星期六 12时46分31秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, ufs[1010];

struct node
{
	int x, y, t;
}city[100010];

bool cmp(node a, node b)
{
	return a.t < b.t;
}

int find(int x)
{
	if (x != ufs[x]) return ufs[x] = find(ufs[x]);
	return ufs[x] = x;
}

bool judge()
{
	for (int i = 1; i <= n / 2 + 1; ++i)
	{
		if (find(i) != find(n - i + 1))
			return false;
		return true;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &city[i].x, &city[i].y, &city[i].t);
	}
	for (int i = 1; i <= n; ++i)
	{
		ufs[i] = i;
	}
	sort(city + 1, city + 1 + m, cmp);
	for (int i = 1; i <= m; ++i)
	{
		a = find(city[i].x); b = find(city[i].y);
		if (a != b)
		{
			ufs[a] = b;
			if (judge())
			{
				printf("%d\n", city[i].t);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
