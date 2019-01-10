/*************************************************************
 *  > File Name        : P1547.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月10日 星期四 12时51分03秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 2010;
const int maxm = 100010;

int n, m, u, v, c, ans, ufs[maxn];

int find(int x)
{
    if (ufs[x] != x) return ufs[x] = find(ufs[x]);
    return ufs[x];
}

void unionn(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) ufs[fx] = fy;
}

struct Edge
{
    int x, y, v;
    bool operator < (const Edge &a) const
    {
        if (v != a.v) return v < a.v;
		if (x != a.x) return x < a.x;
		return y < a.y;
    } 
}edge[maxm];

void kruskal()
{
    int k = 0;
    for (int i = 1; i <= n; ++i)
        ufs[i] = i;
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; ++i)
    {
        if (k == n - 1) break;
        if (find(edge[i].x) != find(edge[i].y))
        {
            unionn(edge[i].x, edge[i].y);
            k++;
            ans = edge[i].v;
        }
    }
    return;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &u, &v, &c);
		edge[i] = (Edge){u, v, c};
	}
	kruskal();
	printf("%d\n", ans);
	return 0;
}
