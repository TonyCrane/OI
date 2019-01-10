/*************************************************************
 *  > File Name        : P2820.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月10日 星期四 12时25分37秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int maxm = maxn * (maxn - 1) / 2;

int n, m, I, J, M, ans, sum;
int ufs[maxn];

int find(int x)
{
	if (ufs[x] != x) return ufs[x] = find(ufs[x]);
	return ufs[x] = x;
}

void unionn(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if (fx != fy)
	{
		ufs[fx] = fy;
	}
}

struct Edge
{
	int a, b, f;
	bool operator < (const Edge &x) const
	{
		if (f != x.f) return f < x.f;
		if (a != x.a) return a < x.a;
		return b < x.b;
	}
}edge[maxm];

void Kruskal()
{
	for (int i = 1; i <= n; ++i)
	{
		ufs[i] = i;
	}
	int k, x, y;
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= m; ++i)
	{
		if (k == n - 1) break;
		x = find(edge[i].a);
		y = find(edge[i].b);
		if (x != y)
		{
			unionn(x, y);
			k++;
			ans += edge[i].f;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &I, &J, &M);
		edge[i] = (Edge){I, J, M};
		sum += M;
	}
	Kruskal();
	printf("%d\n", sum - ans);
	return 0;
}
