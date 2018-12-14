#include<bits/stdc++.h>
using namespace std;

int n, m;
int main_w[70], main_c[70];
int other_w[70][3], other_c[70][3];
int dp[32010];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= m; ++i)
	{
		int v, p, q;
		scanf("%d %d %d", &v, &p, &q);
		if (q == 0)
		{
			main_w[i] = v;
			main_c[i] = v * p;
		}
		else
		{
			other_w[q][0]++;
			other_w[q][other_w[q][0]] = v;
			other_c[q][other_w[q][0]] = v * p;
		}
	}

	for (int i = 1; i <= m; ++i)
		for (int j = n; j >= main_w[i]; --j)
		{
			dp[j] = max(dp[j], dp[j - main_w[i]] + main_c[i]);
			if (j >= main_w[i] + other_w[i][1])
				dp[j] = max(dp[j], dp[j - main_w[i] - other_w[i][1]] + main_c[i] + other_c[i][1]);
		    if (j >= main_w[i] + other_w[i][2])
				dp[j] = max(dp[j], dp[j - main_w[i] - other_w[i][2]] + main_c[i] + other_c[i][2]);
			if (j >= main_w[i] + other_w[i][1] + other_w[i][2])
				dp[j] = max(dp[j], dp[j - main_w[i] - other_w[i][1] - other_w[i][2]] + main_c[i] + other_c[i][1] + other_c[i][2]);
		}
	
	printf("%d\n", dp[n]);
	return 0;
}
