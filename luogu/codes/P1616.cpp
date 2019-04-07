#include<bits/stdc++.h>
using namespace std;

int T, M, t[10010], v[10010], dp[100010];

int main()
{
	scanf("%d %d", &T, &M);
	for (int i = 1; i <= M; ++i)
		scanf("%d %d", &t[i], &v[i]);
	for (int i = 1; i <= M; ++i)
		for (int j = t[i]; j <= T; ++j)
			dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
	printf("%d\n", dp[T]);
	return 0;
}
