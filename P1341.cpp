#include<bits/stdc++.h>
using namespace std;

const int maxn = 100;
const int maxm = 500;

int n, road[maxm], roadi, cnt;
bool vis[2 * maxm];

int head[maxn];
struct Edge
{
	int to, next;
}edge[maxm];

void add(int t, int nxt)
{
	edge[++cnt].to = nxt;
	edge[cnt].next = head[t];
	head[t] = cnt;
}

void dfs(int now)
{
	for (int i = head[now]; i != 0; i = edge[i].next)
	{
		if (!vis[i])
		{
			vis[i] = true;
			vis[i ^ 1] = true;
			dfs(edge[i].to);
			road[roadi++] = i;
		}
	}
}

int main()
{
	scanf("%d", &n);
	int ch1, ch2;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d", &ch1, &ch2);
		add(ch1, ch2); add(ch2, ch1);
	}
	dfs(1);
	if (roadi <= n)
	{
		printf("No Solution\n");
	}
	else
	{
		for (int i = roadi; i >= 0; i--)
		{
			printf("%c", road[i]);
		}
	}
	return 0;
}
