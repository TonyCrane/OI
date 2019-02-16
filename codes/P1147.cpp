/*************************************************************
 *  > File Name        : P1147.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月16日 星期六 19时29分23秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, sum;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; ++i)
	{
		sum = 0;
		for (int j = i; ; ++j)
		{
			sum += j;
			if (sum > n) break;
			if (sum == n)
			{
				printf("%d %d\n", i, j);
				break;
			}
		}
	}
	return 0;
}
