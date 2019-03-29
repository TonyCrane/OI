/*************************************************************
 *  > File Name        : P1196.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年03月29日 星期五 12时34分54秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int t, x, y;
char opt;

int ufs[30010], dis[30010], num[30010];

int find(int x)
{
	if (ufs[x] == x) return x;
	int fx = find(ufs[x]);
	dis[x] += dis[ufs[x]];
	return ufs[x] = fx;
}

int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= 30000; ++i)
	{
		ufs[i] = i;
		dis[i] = 0;
		num[i] = 1;
	}
	while (t--)
	{
		cin >> opt >> x >> y;
		int fx = find(x);
		int fy = find(y);
		if (opt == 'M')
		{
			dis[fx] += num[fy];
			ufs[fx] = fy;
			num[fy] += num[fx];
			num[fx] = 0;
		}
		else if (opt == 'C')
		{
			if (fx != fy) printf("-1\n");
			else printf("%d\n", abs(dis[x] - dis[y]) - 1);
		}
	}
	return 0;
}
