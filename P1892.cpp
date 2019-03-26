/*************************************************************
 *  > File Name        : pj.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年03月25日 星期一 13时05分27秒
**************************************************************/
 
#include <bits/stdc++.h>
using namespace std;
 
int n, m, ufs[2020], x, y, ans;
char p;
 
int find(int x)
{
    if (ufs[x] == x) return x;
    else return ufs[x] = find(ufs[x]);
}
 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; ++i)
        ufs[i] = i;
    for (int i = 1; i <= m; ++i)
    {
		cin >> p >> x >> y;
        if (p == 'F') ufs[find(x)] = find(y);
        if (p == 'E')
        {
            ufs[find(x + n)] = find(y);
            ufs[find(y + n)] = find(x);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (ufs[i] == i)
            ans++;
    printf("%d\n", ans);
    return 0;
}
