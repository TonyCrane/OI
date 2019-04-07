#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n, map[101][201], lent, ans, len = -1;
int go[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
string st;

void map_get()
{
	getline(cin, st);
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; ++i)
	{
		getline(cin, st);
		lent = st.size();
		len = max(lent, len);
		for (int j = 0; j < lent; ++j)
			if (st[j] >= 'a' && st[j] <= 'z')
				map[i][j] = 1;
	}
}

void dfs(int x, int y)
{
	map[x][y] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int x2 = x + go[i][0];
		int y2 = y + go[i][1];
		if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= len || !map[x2][y2]) continue;
		dfs(x2, y2);
	}
}

int main()
{
//	freopen("P1767.in", "r", stdin);
	scanf("%d", &n);
	map_get();
//	for (int i = 1; i <= 4; ++i)
//		{for (int j = 0; j < 11; ++j)
//			cout << map[i][j];
//		cout << endl;}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < len; ++j)
			if (map[i][j])
			{
				dfs(i, j);
				ans++;
			}
	cout << ans <<endl;
	return 0;
}
