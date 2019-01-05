/*************************************************************
 *  > File Name        : P2661.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月02日 星期三 13时03分29秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int f[200010], dis[200010], n, minx = 1e9, last;

int find(int x)
{
	if (f[x] != x)
	{
		int last = f[x];
		f[x] = find(f[x]);
		dis[x] += dis[last];
	}
	return f[x];
}

void check(int a, int b)
{
	int x = find(a), y = find(b);
	if (x != y)
	{
		f[x] = y;
		dis[a] = dis[b] + 1;
	}
	else
	{
		minx = min(minx, dis[a] + dis[b] + 1);
	}
	return;
}

int main()
{
	int t;
    scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		f[i] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &t);
		check(i, t);
	}
	printf("%d\n", minx);
    return 0;
}
