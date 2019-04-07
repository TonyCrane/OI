#include<bits/stdc++.h>
using namespace std;

const int maxn = 500;

int n, G[maxn][maxn], ansi, deg[maxn];
char tmp[maxn], ans[maxn * maxn];

void dfs(int i)
{
	for (int j = 1; j <= maxn; ++j)
	{
		if (G[i][j] > 0)
		{
			G[i][j] = 0;
			G[j][i] = 0;
			dfs(j);
		}
	}
	ans[++ansi] = i;
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", tmp);
		G[tmp[0]][tmp[1]] = 1;
		G[tmp[1]][tmp[0]] = 1;
		deg[tmp[0]]++;
		deg[tmp[1]]++;
	}
	char cnt = 0, h = 0;
	for (int i = 1; i <= maxn; ++i)
	{
		if (deg[i] & 1)
		{
			cnt++;
			if (!h)
			{
				h = i;
			}
		}
	}
	if (!h)
	{
		for (int i = 0; i <= maxn; ++i)
		{
			if (deg[i])
			{
				h = i;
				break;
			}
		}
	}
	if (cnt && cnt != 2)
	{
		printf("No Solution\n");
		return 0;
	}
	dfs(h);
	for (int i = ansi; i >= 1; i--)
	{
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}
