#include<bits/stdc++.h>
using namespace std;

const int maxn = 510;
int s, n, m, cnt, ufs[maxn];
double ans[maxn];

struct Point
{
	int x, y;
}point[maxn];

struct Edge
{
	int from, to;
	double val;
	bool operator < (const Edge& a) const
	{
		return val < a.val;
	}
}edge[maxn * maxn];

double dist(Point a, Point b)
{
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

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

void kruskal()
{
	int k = 0;
	for (int i = 1; i <= n; ++i)
		ufs[i] = i;
	sort(edge + 1, edge + 1 + m);
	for (int i = 1; i <= m; ++i)
	{
		if (k == n - 1) break;
		if (find(edge[i].from) != find(edge[i].to))
		{
			unionn(edge[i].from, edge[i].to);
			ans[++k] = edge[i].val;
		}
	}
	sort(ans + 1, ans + n);
	return;
}

int main()
{
	scanf("%d %d", &s, &n);
	m = n * (n - 1) / 2;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j)
				edge[++cnt] = (Edge){i, j, dist(point[i], point[j])};
	kruskal();
	printf("%.2f", ans[n - s]);
	return 0;
}
