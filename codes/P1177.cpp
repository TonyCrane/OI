/*快排模板*/
#include<bits/stdc++.h>
using namespace std;

int a[100010];

void qsort(int l, int r)
{
	int i, j, mid, p;
	i = l; j = r;
	mid = a[(l + r) / 2];
	do
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j)
		{
			p = a[i];
			a[i] = a[j];
			a[j] = p;
			i++; j--;
		}
	}while(i <= j);
	if (l < j) qsort(l, j);
	if (i < r) qsort(i, r);
}

int main()
{
	int n, i;
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> a[i];
	qsort(1, n);
	for (i = 1; i <= n; ++i)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
