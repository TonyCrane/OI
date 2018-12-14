#include<bits/stdc++.h>
using namespace std;

int n, a[10010], sum, ave, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	ave = sum / n;
	for (int i = 0; i < n; ++i) a[i] -= ave;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0) continue;
		a[i + 1] += a[i];
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
