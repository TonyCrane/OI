#include<bits/stdc++.h>
using namespace std;

int n, m, sx, sy, vis[210][210], ans[210][210];
int gox[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int goy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct horse
{
	int x, y;
}node, top;

queue<horse> que;

void bfs()
{
	vis[sx][sy] = 1;
	node.x = sx;
	node.y = sy;
	que.push(node);
	ans[sx][sy] = 0;
	while(!que.empty())
	{
		top = que.front();
		for (int i = 0; i < 8; ++i)
		{
			int x2 = top.x + gox[i];
			int y2 = top.y + goy[i];
			if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && !vis[x2][y2])
			{
				ans[x2][y2] = ans[top.x][top.y] + 1;
				vis[x2][y2] = 1;
				node.x = x2;
				node.y = y2;
				que.push(node);
			}
		}
		que.pop();
	}
	return;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &sx, &sy);
	memset(ans, -1, sizeof(ans));
	bfs();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			printf("%-5d", ans[i][j]);
		printf("\n");
	}
	return 0;
}
