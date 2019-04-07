#include<bits/stdc++.h>
using namespace std;

int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, cnt, sum[1010 * 1010], vis[1010][1010];
char _map[1010][1010];

struct Node
{
	int x, y;
	Node(){}
	Node(int a, int b)
	{
		x = a;
		y = b;
	}
}Q[1010 * 1010];

void bfs(int x, int y, int k)
{
	int head = 0, tail = 0;
	Q[tail++] = Node(x, y);
	vis[x][y] = k;
	sum[k] = 1;
	while (head < tail)
	{
		Node now = Q[head++];
		for (int i = 0; i < 4; ++i)
		{
			int x2 = now.x + go[i][0];
			int y2 = now.y + go[i][1];
			if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && !vis[x2][y2] && _map[now.x][now.y] != _map[x2][y2])
			{
				vis[x2][y2] = k;
				sum[k]++;
				Q[tail++] = Node(x2, y2);
			}
		}
	}
	return;
}

int main()
{
	freopen("P1141.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", _map[i]);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		if (!vis[a][b]) bfs(a, b, ++cnt);
		printf("%d\n", sum[vis[a][b]]);
	}
	return 0;
}
