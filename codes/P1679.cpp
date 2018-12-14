#include<bits/stdc++.h>
using namespace std;

int m, s[200010], dp[200010];

int main()
{
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		dp[i] = 1e9;
	int tmp = ceil(sqrt(sqrt(m)) + 1);
	for (int i = 1; i <= tmp; ++i)
		s[i] = pow(i, 4);
	for (int i = 1; i <= tmp; ++i)
		for (int j = s[i]; j <= m; ++j)
			dp[j] = min(dp[j], dp[j - s[i]] + 1);
	printf("%d\n", dp[m]);
	return 0;
}
