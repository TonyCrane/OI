#include<bits/stdc++.h>
using namespace std;

int n, m, x[5010], a[5010];
int ans, tmp;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
	sort(x + 1, x + 1 + n);
	for (int i = 1; i <= n; ++i)
	{
		if (!a[i])
		{
			a[i] = 1;
			ans++;
			tmp = 0;
			for (int j = i + 1; j <= n; ++j)
			{
				if (!a[j] && tmp + 1 <= x[j])
				{
					a[j] = 1;
					tmp++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
