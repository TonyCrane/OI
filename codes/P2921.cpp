/*************************************************************
 *  > File Name        : P2921.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月06日 星期日 12时19分27秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int n, in[maxn], col[maxn], sdfn[maxn], dfn[maxn], minc[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &in[i]);
	}
	for (int cow = 1; cow <= n; ++cow)
	{
		for (int i = cow, cnt = 0; ; i = in[i], ++cnt)
		{
			if (!col[i])
			{
				col[i] = cow;
				dfn[i] = cnt;
			}
			else if (col[i] == cow)
			{
				minc[cow] = cnt - dfn[i];
				sdfn[cow] = dfn[i];
				printf("%d\n", cnt);
				break;
			}
			else
			{
				minc[cow] = minc[col[i]];
				sdfn[cow] = cnt + max(sdfn[col[i]] - dfn[i], 0);
				printf("%d\n", sdfn[cow] + minc[cow]);
				break;
			}
		}
	}
	return 0;
}
