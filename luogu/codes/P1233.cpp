/*************************************************************
 *  > File Name        : P1233.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月20日 星期三 12时18分43秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int l, w;
}node[5010];

bool cmp(Node a, Node b)
{
	if (a.l == b.l) return a.w > b.w;
	return a.l > b.l;
}

int n, ans, tmp;
bool vis[5010];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &node[i].l, &node[i].w);
	sort(node + 1, node + 1 + n, cmp);
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			tmp = node[i].w;
			for (int j = i + 1; j <= n; ++j)
			{
				if (node[j].w <= tmp && !vis[j])
				{
					vis[j] = true;
					tmp = node[j].w;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			ans++;
	printf("%d\n", ans);
	return 0;
}
