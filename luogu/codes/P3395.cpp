#include<bits/stdc++.h>
using namespace std;

int T, n, go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool vis[2500][2500];

struct Point
{
	int x, y, time;
	Point(){}
	Point(int a, int b, int c)
	{
		x = a;
		y = b;
		time = c;
	}
}node, top, point[2500];
queue<Point> que;

void bfs()
{
	bool flag = false;
	vis[1][1] = 1;
	node = Point(1, 1, 1);
	que.push(node);
	while (!que.empty())
	{
		top = que.front();
		if (top.x == n && top.y == n);
		{
			flag = true;
			printf("Yes\n");
			break;
		}
		vis[point[top.time - 1].x][point[top.time - 1].y] = 1;
		for (int i = 0; i < 4; ++i)
		{
			int x2 = top.x + go[i][0];
			int y2 = top.y + go[i][1];
			if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= n && !vis[x2][y2])
			{
				vis[x2][y2] = 1;
				node = Point(x2, y2, top.time + 1);
				que.push(node);
			}
		}
		que.pop();
	}
	if (!flag) printf("No\n");
}

int main()
{
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		memset(point, 0, sizeof(point));
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for (int j = 1; j <= 2 * n - 2; ++j)
			scanf("%d %d", &point[j].x, &point[j].y);
		while (!que.empty()) que.pop();
		bfs();
	}
	return 0;
}
