/*************************************************************
 *  > File Name        : P1996.cpp
 *  > Author           : Tony
 *  > Created Time     : 2018年12月25日 星期二 12时40分51秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
bool vis[210];

int main()
{
    scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (++ans > n) ans = 1;
			if (vis[ans]) j--;
		}
		printf("%d ", ans);
		vis[ans] = true;
	}
    return 0;
}
