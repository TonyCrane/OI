#include<bits/stdc++.h>
using namespace std;

int n;
double d = 0;

struct point
{
	int x;
	int y;
	int z;
}a[50010];

double dist(point a, point b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

bool cmp(point a, point b)
{
	return a.z < b.z;
}

int main()
{
	cin>>n;
	for (int i = 1; i <= n; ++i)
		cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i < n; ++i)
		d += dist(a[i], a[i + 1]);
	printf("%0.3f\n", d);
	return 0;
}
