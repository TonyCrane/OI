#include<bits/stdc++.h>
using namespace std;

int n, m, a[100010], l = 0, ans = 1;

int main()
{
//	freopen("P1181.in", "r", stdin);
	cin>>n>>m;
	for (int i = 1; i <= n; ++i) cin>>a[i];
	for (int i = 1; i <= n; ++i)
	{
		if (l + a[i] <= m)
			l += a[i];
		else
		{
			ans += 1;
			l = a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
