/*************************************************************
 *  > File Name        : P1118.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月16日 星期日 20时32分57秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, sum, ans[20], pc[20];
bool vis[20];

bool dfs(int i, int num, int s)
{
	if (s > sum) return false;
	if (i == n)
	{
		if (s == sum)
		{
			ans[i] = num;
			return true;
		}
		else return false;
	}

	vis[num] = true;
	for (int j = 1; j <= n; ++j)
		if (!vis[j] && dfs(i + 1, j, s + pc[i] * j))
		{
			ans[i] = num;
			return true;
		}
	vis[num] = false;
	return false;
}

int main()
{
	scanf("%d %d", &n, &sum);
	pc[0] = pc[n - 1] = 1;
	if (n > 1)
		for (int i = 1; i * 2 < n; ++i)
			pc[i] = pc[n - 1 - i] = (n - i) * pc[i - 1]/i;
	if (dfs(0, 0, 0))
		for (int i = 1; i <= n; ++i)
			printf("%d ", ans[i]);
    return 0;
}
