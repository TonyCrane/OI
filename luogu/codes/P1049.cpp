#include<bits/stdc++.h>
using namespace std;

int V, n, v[40], dp[20010];

int main()
{
	scanf("%d%d", &V, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &v[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = V; j >= v[i]; --j)
			dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
	printf("%d\n", V - dp[V]);
	return 0;
}
