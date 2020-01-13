/*************************************************************
 *  > File Name        : pg.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月14日 星期一 12时39分10秒
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, t = 0, k = 3;

int main()
{
    scanf("%d", &n);
	int m = n;
    while (t <= n) 
	{
		t = t * 2 + k;
		k++;
	}
    k--;
    while (t > 0)
    {
        t = (t - k) / 2;
        if (m > t)
        {
            if (m <= t + k)
            {
                if (m == t + 1) return printf("m"), 0;
                else printf("o"), 0;
            }
            else m = m - ( t + k);
        }
        k--;
    }
    return 0;
}
