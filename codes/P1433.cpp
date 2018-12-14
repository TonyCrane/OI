#include<bits/stdc++.h>
using namespace std;

int n;
bool vis[20];
double ans = 999999999.0;

struct Point
{
	double x, y;
	Point(){}
	Point(double a, double b)
	{
		x = a; y = b;
	}
}point[20];

double dist(Point a, Point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void dfs(int already, int now, double len)
{
	if (len > ans) return;
	if (already == now)
	{
		ans = min(ans, len);
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i])
		{
			vis[i] = true;
			dfs(already + 1, i, len + dist(point[i], point[i + 1]));
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("P1433.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lf %lf", &point[i].x, &point[i].y);
	point[0] = Point(0.0, 0.0);
	dfs(0, 0, 0.0);
	printf("%.2f\n", ans);
	return 0;
}
