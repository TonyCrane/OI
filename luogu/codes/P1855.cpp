#include<bits/stdc++.h>
using namespace std;

int n, M, T, dp[1010][1010], m[1010], t[1010];

int main()
{
	scanf("%d %d %d", &n, &M, &T);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &m[i], &t[i]);
		for (int j = M; j >= m[i]; --j)
			for (int k = T; k >= t[i]; --k)
				dp[j][k] = max(dp[j][k], dp[j - m[i]][k - t[i]] + 1);
	}
	printf("%d\n", dp[M][T]);
	return 0;
}
