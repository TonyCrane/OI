#include<bits/stdc++.h>
using namespace std;

int n, m, sx, sy, vis[210][210], que[50000][2], ans[210][210];
int gox[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int goy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs()
{
	int head = 1, tail = 2;
	vis[sx][sy] = 1;
	que[head][0] = sx;
	que[head][1] = sy;
	ans[sx][sy] = 0;
	while (head < tail)
	{
		int x, x2, y, y2;
		x = que[head][0];
		y = que[head][1];
		for (int i = 0; i < 8; ++i)
		{
			x2 = x + gox[i];
			y2 = y + goy[i];
			if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && !vis[x2][y2])
			{
				ans[x2][y2] = ans[x][y] + 1;
				vis[x2][y2] = 1;
				que[tail][0] = x2;
				que[tail][1] = y2;
				tail++;
			}
		}
		head++;
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
