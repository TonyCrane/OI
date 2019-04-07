#include<bits/stdc++.h>
using namespace std;

int a[1010], b[1010], dp[1010][15000];
int n, ans, len;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &a[i], &b[i]);
	for (int i = 0; i <= 1000; ++i)
		for (int j = 0; j <= 14000; ++j)
			dp[i][j] = 1e9;
	dp[0][5000] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = -5000; j <= 5000; ++j)
		{
			len = a[i] - b[i];
			dp[i][j + 5000] = min(dp[i - 1][j - len + 5000], dp[i - 1][j + len + 5000] + 1);
		}
	for (int i = 0; i <= 5000; ++i)
	{
		ans = min(dp[n][i + 5000], dp[n][5000 - i]);
		if (ans <= 1000)
		{
			printf("%d\n", ans);
			break;
		}
	}
	return 0;
}
