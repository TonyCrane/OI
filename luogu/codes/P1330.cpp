#include<bits/stdc++.h>
using namespace std;

bool vis[20010] = {0};
int col[20010] = {0}, sum[2];
int n, m, a, b, ans;

int head[20010], cnt = 0;
struct Edge
{
	int t, nexty;
}edge[200010];

void add(int x, int y)
{
	edge[++cnt].t = y;
	edge[cnt].nexty = head[x];
	head[x] = cnt;
}

bool dfs(int node, int color)
{
	if (vis[node])
	{
		if (col[node] == color) return true;
		return false;
	}
	vis[node] = true;
	sum[col[node] = color]++;
	bool bo = true;
	for (int i = head[node]; i != 0 && bo; i = edge[i].nexty)
	{
		bo = bo && dfs(edge[i].t, 1 - color);
	}
	return bo;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &a, &b);
		add(a, b); add(b, a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i]) continue;
		sum[0] = sum[1] = 0;
		if (!dfs(i, 0))
		{
			printf("Impossible\n");
			return 0;
		}
		ans += min(sum[0], sum[1]);
	}
	printf("%d\n", ans);
	return 0;
}
