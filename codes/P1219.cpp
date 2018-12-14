#include<bits/stdc++.h>
using namespace std;

int ans, n, row[50], col[50], dj1[50], dj2[50];

void out_put()
{
	if (ans <= 2)
	{
		for (int i = 1; i <= n; ++i)
			cout << row[i] << " ";
		cout << endl;
	}
	ans++;
	return;
}

void dfs(int a)
{
	if (a > n) out_put();
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if ((!col[i]) && (!dj1[a + i]) && (!dj2[a - i + n]))
			{
				row[a] = i;
				col[i] = 1;
				dj1[a + i] = 1;
				dj2[a - i + n] = 1;
				dfs(a + 1);
				col[i] = 0;
				dj1[a + i] = 0;
				dj2[a - i + n] = 0;
			}
		}
	}
	return;
}

int main()
{
	cin >> n;
	dfs(1);
	cout << ans << endl;
	return 0;
}
