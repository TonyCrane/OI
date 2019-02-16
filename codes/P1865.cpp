/*************************************************************
 *  > File Name        : P1865.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月16日 星期六 22时10分44秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int f[1000010], n, m, l, r;
bool vis[1000010];

void GetPrime(int x)
{
	f[1] = 0;
	vis[1] = true;
	for (int i = 2; i <= x; ++i)
	{
		if (!vis[i])
		{
			f[i] = f[i - 1] + 1;
			for (int j = 2 * i; j <= x; j += i)
			{
				vis[j] = true;
			}
		}
		else
		{
			f[i] = f[i - 1];
		}
	}
	return;
}

int main()
{
	scanf("%d %d", &n, &m);
	GetPrime(m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &l, &r);
		if (l <= 0 || r > m)
		{
			printf("Crossing the line\n");
		}
		else
		{
			printf("%d\n", f[r] - f[l - 1]);
		}
	}
	return 0;
}
