#include<bits/stdc++.h>
using namespace std;

int n, m, ans = 0;

struct farmer
{
	int p;
	int a;
}f[5010];

bool cmp(farmer a. farmer b)
{
	if (a.p != b.p) return a.p < b.p;
	return a.a > b.a;
}

int main()
{
	freopen("P1208.in", "r", stdin);
	cin>>n>>m;
	for (int i = 1; i <= m; ++i) cin>>f[i].p>>f[i].a;
	sort(f + 1, f + 1 + m, cmp);
	int i = 1;
	while(n)
	{
		if (f[i].a != 0)
		{
			f[i].a--;
			ans += f[i].p;
			n--;
		}
		else i++;
	}
	cout<<ans<<endl;
	return 0;
}
