#include<bits/stdc++.h>
using namespace std;

int n;
char a[30][3];

void dfs(char ch)
{
	if (ch != '*')
	{
		printf("%c", ch);
		for (int i = 1; i <= n; ++i)
			if (a[i][0] == ch)
			{
				dfs(a[i][1]);
				dfs(a[i][2]);
			}
	}
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	dfs(a[1][0]);
	return 0;
}
