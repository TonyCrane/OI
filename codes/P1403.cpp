/*************************************************************
 *  > File Name        : P1403.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月16日 星期六 19时52分18秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		ans += n / i;
	printf("%d\n", ans);
	return 0;
}
