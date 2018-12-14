#include<bits/stdc++.h>
using namespace std;

int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int m, n, _map[110][110], ans; 
char st[110];

struct Node
{
	int x, y;
}node, top;
queue<Node> que;

void bfs(int x, int y)
{
	_map[x][y] = 0;
	node.x = x;
	node.y = y;
	que.push(node);
	ans++;
	while (!que.empty())
	{
		top = que.front();
		for (int i = 0; i < 4; ++i)
		{
			int x2 = top.x + go[i][0];
			int y2 = top.y + go[i][1];
			if (x2 >= 1 && x2 <= m && y2 >= 1 && y2 <= n && _map[x2][y2])
			{
				_map[x2][y2] = 0;
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
//	freopen("P1451.in", "r", stdin);
	scanf("%d %d\n", &m, &n);
	for (int i = 0; i <= 109; ++i)
		for (int j = 0; j <= 109; ++j)
			_map[i][j] = 1;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", st + 1);
		for (int j = 1; j <= n; ++j)
			if (st[j] == '0')
				_map[i][j] = 0;
	}
/*	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
			printf("%d", _map[i][j]);
		printf("\n");
	} */
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (_map[i][j])
				bfs(i, j);
	printf("%d", ans);
	return 0;
}
