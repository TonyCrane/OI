/*************************************************************
 *  > File Name        : P1111.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月05日 星期六 12时46分31秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int ufs[maxn];
int n, m, x, y, q;

int find(int x)
{
	if (ufs[x] != x) return find(ufs[x]);
	else return x;
}

void unionn(int r1, int r2)
{
	ufs[r2] = r1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) ufs[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d", &x, &y);
		int r1 = find(x);
		int r2 = find(y);
		if (r1 != r2) unionn(r1, r2);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
	{
		scanf("%d %d", &x, &y);
		if (find(x) == find(y)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
