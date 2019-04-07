/*************************************************************
 *  > File Name        : P1338.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月18日 星期一 12时21分22秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
	scanf("%d %d", &n, &m);
	int p = n, c = 0;
	for (int i = 1; m > 0; ++i, --p)
		m -= c = min(i, m);
	for (int i = 1; i < p; ++i)
		printf("%d ", i);
	printf("%d ", p + c);
	for (int i = n; i >= p; --i)
		if (i != p + c)
			printf("%d ", i);
	return 0;
}
