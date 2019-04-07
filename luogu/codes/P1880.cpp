#include<bits/stdc++.h>
using namespace std;

const int maxn = 110, MAX = 0x7fffffff;
int dp1[maxn][maxn], dp2[maxn][maxn], s[maxn][maxn];
int a[maxn], sum[maxn], n, ans1, ans2;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i <= n * 2; ++i)
	{
		sum[i] = sum[i - 1] + a[i];
		dp1[i][i] = 0; dp2[i][i] = 0;
	}

	for (int L = 2; L <= n; ++L)
		for (int i = 1; i <= 2 * n - L + 1; ++i)
		{
			int j = i + L - 1;
			dp1[i][j] = MAX; dp2[i][j] = 0;
			for (int k = i; k < j; ++k)
			{
				dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k + 1][j]);
				dp2[i][j] = max(dp2[i][j], dp2[i][k] + dp2[k + 1][j]);
			}
			dp1[i][j] += sum[j] - sum[i - 1];
			dp2[i][j] += sum[j] - sum[i - 1];
		}
	ans1 = MAX; ans2 = -MAX;
	for (int i = 1; i <= n; ++i) ans1 = min(ans1, dp1[i][i + n - 1]);
	for (int i = 1; i <= n; ++i) ans2 = max(ans2, dp2[i][i + n - 1]);

	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
