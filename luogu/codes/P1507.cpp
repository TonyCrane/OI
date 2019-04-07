#include<bits/stdc++.h>
using namespace std;

int Vm, Mm, n, v[60], m[60], cal[60], dp[510][510];

int main()
{
	scanf("%d %d", &Vm, &Mm);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d %d", &v[i], &m[i], &cal[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = Mm; j >= m[i]; --j)
			for (int k = Vm; k >= v[i]; --k)
				dp[j][k] = max(dp[j][k], dp[j - m[i]][k - v[i]] + cal[i]);
	printf("%d\n", dp[Mm][Vm]);
	return 0;
}
