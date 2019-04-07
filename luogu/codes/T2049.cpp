#include<bits/stdc++.h>
using namespace std;

int n, ti[100010], tim = 0, ans;

struct water
{
	int d;
	int t;
}a[100010];

int func(int i)
{
	int tmp = i;
	if (a[i].d != tmp)
	{
		tim += a[i].t;
		func(a[i].d);
	}
	else 
	{
		tim += a[i].t;
	}
	return tim;
}

int main()
{
	freopen("T2049.in", "r", stdin);
	cin>>n;
	for (int i = 1; i <= n; ++i) cin>>a[i].d>>a[i].t;
	for (int i = 1; i <= n; ++i) ti[i] = func(i);
	for (int i = 1; i <  n; ++i) ans = max(ti[i], ti[i + 1]);
	cout<<ans<<endl;
	return 0;
}
