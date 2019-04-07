#include<bits/stdc++.h>
using namespace std;

int m, n, a[1010], b[1010], c[1010][20], cc[101], cnt;
int dp[1010];

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; ++i)
	{
		int C;
		scanf("%d %d %d", &a[i], &b[i], &C);
		cnt = max(cnt, C);
		cc[C]++;
		c[C][cc[C]] = i;
	}
	for (int i = 1; i <= cnt; ++i)
		for (int j = m; j >= 0; --j)
			for (int k = 1; k <= cc[i]; ++k)
				if (j >= a[c[i][k]])
					dp[j] = max(dp[j], dp[j - a[c[i][k]]] + b[c[i][k]]);
	printf("%d\n", dp[m]);
	return 0;
}
