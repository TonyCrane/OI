#include<bits/stdc++.h>
using namespace std;

int n, h[110], dp[2][300], ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	h[0] = 0; h[n + 1] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < i; ++j)
			if (h[i] > h[j])
				dp[0][i] = max(dp[0][i], dp[0][j] + 1);
	for (int i = n; i >= 1; --i)
		for (int j = n + 1; j > i; --j)
			if (h[i] > h[j])
				dp[1][i] = max(dp[1][i], dp[1][j] + 1);
	for (int i = 1; i <= n; ++i)
		ans = max(dp[0][i] + dp[1][i] - 1, ans);
	printf("%d\n", n - ans);
	return 0;
}
