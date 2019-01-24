/*************************************************************
 *  > File Name        : P1522.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月24日 星期四 16时13分02秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 150;
const int inf = 100000000;

int n;
double dist[maxn][maxn], ldis[maxn], li, l2 = inf, ans;

struct Point
{
	int x, y;
	double distance(const Point& a)
	{
		return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
	}
}point[maxn];

int main()
{
	//init
	int tmp;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &point[i].x, &point[i].y);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			scanf("%1d", &tmp);
			if (tmp) dis[i][j] = point[i].distance(point[j]);
			else if (i != j) dis[i][j] = inf;
		}
	
	//floyd
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	
	//find
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			if (dis[i][j] != inf) ldis[i] = max(dis[i][j], ldis[i]);
			li = max(li, ldis[i]);
		}

	//try
	
}
