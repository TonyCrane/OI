/*************************************************************
 *  > File Name        : P1434.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月18日 星期二 13时14分13秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int r, c, anss, h[110][110], ans[110][110];
int go[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dfs(int x, int y)
{
	if (ans[x][y]) return ans[x][y];
	int tmp = 1;
	for (int i = 0; i < 4; ++i)
	{
		int x2 = x + go[i][0];
		int y2 = y + go[i][1];
		if (x2 >= 1 && x2 <= r && y2 >= 1 && y2 <= c && h[x][y] > h[x2][y2])
			tmp = max(dfs(x2, y2) + 1, tmp);
	}
	ans[x][y] = tmp;
	return tmp;
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			scanf("%d", &h[i][j]);
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
		{
			ans[i][j] = dfs(i, j);
			anss = max(anss, ans[i][j]);
		}
	printf("%d\n", anss);
    return 0;
}
