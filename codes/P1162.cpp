#include<bits/stdc++.h>
using namespace std;

int _map[35][35], vis[35][25], n;
int go[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Node
{
	int x;
	int y;
}node, top;

queue<Node> que;

void bfs(int x, int y)
{
	_map[x + 1][y + 1] = 2;
	node.x = x + 1;
	node.y = y + 1;
	que.push(node);
	while (!que.empty())
	{
		top = que.front();
		for (int i = 0; i < 4; ++i)
		{
			int x2 = top.x + go[i][0];
			int y2 = top.y + go[i][1];
			if (x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= n && _map[x2][y2] == 0)
			{
				_map[x2][y2] = 2;
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
//	freopen("P1162.in", "r", stdin);
	scanf("%d", &n);
	bool fini = false;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &_map[i][j]);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (_map[i][j])
			{
				bfs(i, j);
				fini = true;
				break;
			}
		if (fini) break;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%d ", _map[i][j]);
		printf("\n");
	}
	return 0;
}
