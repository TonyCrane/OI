/*************************************************************
 *  > File Name        : P1582.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月18日 星期一 12时30分53秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int main()
{
	scanf("%d %d", &n, &k);
	while (__builtin_popcount(n) > k)
	{
		ans += n & -n;
		n += n & -n;
	}
	printf("%d\n", ans);
	return 0;
}
