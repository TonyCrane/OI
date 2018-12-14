#include<bits/stdc++.h>
using namespace std;

int N, V, v[30], w[30];
int f[30010];

int main()
{
	scanf("%d %d", &V, &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d %d", &v[i], &w[i]);
		w[i] *= v[i];
	}
	for (int i = 1; i <= N; ++i)
		for (int j = V; j >= v[i]; --j)
			if (j >= v[i])
				f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d\n", f[V]);
	return 0;
}
