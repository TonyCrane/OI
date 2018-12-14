#include<bits/stdc++.h>
using namespace std;

int n, k, sum[10001], num = 1, dp[10001];

struct Node
{
	int p, t;
}node[10010];

bool cmp(Node a, Node b)
{
	return a.p > b.p;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d %d", &node[i].p, &node[i].t);
		sum[node[i].p]++;
	}
	sort(node + 1, node + 1 + k, cmp);
	for (int i = n; i >= 1; --i)
	{
		if (sum[i] == 0)
			dp[i] = dp[i + 1] + 1;
		else
		{
			for (int j = 1; j <= sum[i]; ++j)
			{
				if (dp[i + node[num].t] > dp[i])
					dp[i] = dp[i + node[num].t];
				num++;
			}
		}
	}
	printf("%d\n", dp[1]);
	return 0;
}
