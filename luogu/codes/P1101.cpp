#include<bits/stdc++.h>
using namespace std;

int n, sum, ans[110][110];
int go[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
char input[110][110], yz[8] = "yizhong";

struct ques
{
	int x;
	int y;
}que[110];

void dfs(int x, int y, int k, int sum)
{
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (input[x][y] != yz[sum]) return;
	que[sum].x = x;
	que[sum].y = y;
	if (sum == 6)
	{
		for (int i = 0; i < 7; ++i)
			ans[que[i].x][que[i].y] = 1;
		return;
	}
	dfs(x + go[k][0], y + go[k][1], k, sum + 1);
}

int main()
{
//	freopen("P1101.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", input[i]);
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//			cout << input[i][j];
//		cout << endl;
//	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (input[i][j] == 'y')
				for (int k = 0; k < 8; ++k)
						dfs(i, j, k, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (ans[i][j] == 1) cout << input[i][j];
			else if (ans[i][j] == 0) cout << "*";
		}
		cout << endl;
	}
	return 0;
}
