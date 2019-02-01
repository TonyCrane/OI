/*************************************************************
 *  > File Name        : P1216.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/02/01 17:00:40
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, a[1002], ans, p;

int main()
{
    scanf("%d",&n);
    for(int i = n; i; i--)
        for(int j = i; j <= n; j++)
        {
            scanf("%d", &p);
            a[j] = max(a[j], a[j + 1]) + p;
        }
    for(int i = 1; i <= n; i++)
        ans = max(ans, a[i]);
    printf("%d", ans);
    return 0;
}