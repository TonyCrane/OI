/*************************************************************
 *  > File Name        : P1466.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月23日 星期三 16时17分57秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

long long n, m, dp[1000010];

int main()
{
	scanf("%lld", &n);
	m = (n * (n + 1)) / 2;
	if (m % 2)
	{
		printf("0\n");
		return 0;
	}
	m /= 2;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = m; j >= i; --j)
			dp[j] += dp[j - i];
	printf("%d\n", dp[m] / 2);
	return 0;
}
