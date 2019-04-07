/*************************************************************
 *  > File Name        : P3368.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月20日 星期三 16时31分05秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[500010], m, n, tmp, opt, t, l, r, x;

int lowbit(int x)
{
	return x & -x;
}

void change(int x, int y)
{
	while (x <= n)
	{
		a[x] += y;
		x += lowbit(x);
	}
}

int query(int x)
{
	int ans = 0;
	while (x)
	{
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1, tmp = 0; i <= n; ++i)
	{
		scanf("%d", &t);
		change(i, t - tmp);
		tmp = t;
	}
	while (m--)
	{
		scanf("%d", &opt);
		if (opt == 1)
		{
			scanf("%d %d %d", &l, &r, &x);
			change(l, x);
			change(r + 1, -x);
		}
		else
		{
			scanf("%d", &x);
			printf("%d\n", query(x));
		}
	}
	return 0;
}
