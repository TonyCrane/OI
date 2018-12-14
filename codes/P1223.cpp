#include<bits/stdc++.h>
using namespace std;

struct water
{
	int num;
	int t;
}a[1010];

bool cmp(water a, water b)
{
	return a.t < b.t;
}

int main()
{
//	freopen("P1223.in", "r", stdin);
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		a[i].num = i;
		cin>>a[i].t;
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; ++i)
		cout<<a[i].num<<" ";
	cout<<endl;
	double time;
	int j;
	for (int i = n - 1; i >= 1; --i)
	{
		j = n - i;
		time += a[j].t * i;
	}
	printf("%0.2f\n", time / (1.0 * n));
	return 0;
}
