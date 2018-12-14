#include<bits/stdc++.h>
using namespace std;

int T, M, dp[1010], t[110], v[110];

int main()
{
	scanf("%d %d", &T, &M);
	for (int i = 1; i <= M; ++i)
		scanf("%d %d", &t[i], &v[i]);
	for (int i = 1; i <= M; ++i)
		for (int j = T; j >= t[i]; --j)
			dp[j] = max(dp[j - t[i]] + v[i], dp[j]);
	printf("%d", dp[T]);
	return 0;
}
