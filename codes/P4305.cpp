/*************************************************************
 *  > File Name        : P4305.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月28日 星期四 15时51分11秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define p 100003
#define hash(a) a%p

int h[p], t, n, x;

int find(int x)
{
	int y;
	if (x < 0) y = hash(-x);
	else y = hash(x);
	while (h[y] && h[y] != x) y = hash(++y);
	return y;
}

void push(int x)
{
	h[find(x)] = x;
}

bool check(int x)
{
	return h[find(x)] == x;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(h, 0, sizeof(h));
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d", &x);
			if (!check(x))
			{
				printf("%d ", x);
				push(x);
			}
		}
		printf("\n");
	}
	return 0;
}
