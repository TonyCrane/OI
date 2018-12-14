#include<bits/stdc++.h>
using namespace std;

int n, q, a[100010];
long long ans;

void order1(int x, int s)
{
	a[x] += s;
}

void order2(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		ans += 1LL * a[i] * (r - i + 1);
	}
	printf("%lld\n", ans);
	ans = 0;
}

int main()
{
//	freopen("P2826.in", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= q; ++i)
	{
		int order, x, y;
		scanf("%d %d %d", &order, &x, &y);
		if (order == 1) order1(x, y);
		else if (order == 2) order2(x, y);
	}
	return 0;
}
