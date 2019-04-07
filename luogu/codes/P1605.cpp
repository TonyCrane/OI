#include<bits/stdc++.h>
using namespace std;

int n, m, t, sx, sy, fx, fy, ans;
int mg[6][6], now[6][6];
int go[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int x, int y)
{
	int x2, y2;
	if (x == fx && y == fy) ans++;
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			x2 = x + go[i][0];
			y2 = y + go[i][1];
			if (x2 > 0 && x2 <= n && y2 > 0 && y2 <= m && mg[x2][y2] == 0 && now[x2][y2] == 0)
				
			{
				now[x2][y2] = 1;
				dfs(x2, y2);
				now[x2][y2] = 0;
			}
		}
	}
	return;
}

int main()
{
//	freopen("P1605.in", "r", stdin);
	memset(mg, 0, sizeof(mg));
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
	for (int i = 1; i <= t; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		mg[x][y] = 1;
	}
	now[sx][sy] = 1;
	ans = 0;
	dfs(sx, sy);
	printf("%d", ans);
	return 0;
}
