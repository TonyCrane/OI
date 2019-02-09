/*************************************************************
 *  > File Name        : P1063.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月09日 星期六 12时32分35秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, a[300], dp[300][300], ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 2; i <= 2 * n; ++i)
	{
		for (int j = i - 1; j >= 1 && i - j < n; --j)
		{
			for (int k = j; k < i; ++k)
			{
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
				ans = max(ans, dp[j][i]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
