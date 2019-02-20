/*************************************************************
 *  > File Name        : UVa273.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月19日 星期二 12时45分08秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int ufs[20];
 
struct Point
{
    int x1,x2,y1,y2;
    Point(int x1 = 0, int x2 = 0, int y1 = 0, int y2 = 0) : x1(x1), x2(x2), y1(y1), y2(y2) {};
    void read()
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    }
}p[20];
 
void unit(int n)
{
    for (int i = 1; i <= n; i++) ufs[i] = i;
}
 
int find(int x)
{
    return x == ufs[x] ? x : ufs[x] = find(ufs[x]);
}
 
int cross(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}
 
int intersection(Point A, Point B)
{
    int c[4];
    if (max(A.x1, A.x2) < min(B.x1, B.x2) || max(A.y1, A.y2) < min(B.y1, B.y2) || max(B.x1, B.x2) < min(A.x1, A.x2) || max(B.y1, B.y2) < min(A.y1, A.y2) )
		return 0;
    c[0] = cross(A.x2 - A.x1, A.y2 - A.y1, B.x1 - A.x1, B.y1 - A.y1);
    c[1] = cross(A.x2 - A.x1, A.y2 - A.y1, B.x2 - A.x1, B.y2 - A.y1);
    c[2] = cross(B.x2 - B.x1, B.y2 - B.y1, A.x1 - B.x1, A.y1 - B.y1);
    c[3] = cross(B.x2 - B.x1, B.y2 - B.y1, A.x2 - B.x1, A.y2 - B.y1);
    if (c[0] * c[1] <= 0 && c[2] * c[3] <= 0) return 1;
    return 0;
}
 
int main()
{
	int tmp;
	scanf("%d", &tmp);
    int n;
	for (int t = 1; t <= tmp; ++t)
	{
		scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            p[i].read();
        unit(n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (intersection(p[i],p[j]))
                {
                    int a = find(i);
                    int b = find(j);
                    if(a != b) ufs[a] = b;
                }
            }
        }
        int a, b;
        while (~scanf("%d %d",&a,&b), a | b)
        {
            a = find(a);
            b = find(b);
            if (a == b) puts("CONNECTED");
            else puts("NOT CONNECTED");
        }
    }
    return 0;
}

