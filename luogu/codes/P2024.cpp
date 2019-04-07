/*************************************************************
 *  > File Name        : P2024.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月25日 星期五 15时26分18秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, k, ufs[300000], ans = 0;

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
	{
		ufs[fx] = fy;
	}
}

bool same(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx == fy) return true;
	return false;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 3 * n; ++i)
		ufs[i] = i;
	for (int i = 1; i <= k; ++i)
	{
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		
		if (x <= 0 || n < x || y <= 0 || n < y)
		{
			ans++;
			continue;
		}

		if (t == 1)
		{
			if (same(x, y + n) || same(x + n, y))
			{
				ans++;
			}
			else
			{
				unionn(x, y);
				unionn(x + n, y + n);
				unionn(x + 2 * n, y + 2 * n);
			}
		}
		else
		{
			if (same(x, y) || same(x, y + n))
			{
				ans++;
			}
			else
			{
				unionn(x, y + 2 * n);
				unionn(x + n, y);
				unionn(x + 2 * n, y + n);
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
