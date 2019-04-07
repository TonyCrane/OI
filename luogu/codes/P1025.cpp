/*************************************************************
 *  > File Name        : P1025.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/02/01 16:55:40
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, k, cnt;

void dfs(int last, int sum, int cur)
{
    if (cur == k)
    {
        if (sum == n) cnt++;
        return;
    }
    for (int i = last; sum + i * (k - cur) <= n; i++)
        dfs(i, sum + i, cur + 1);
}

int main()
{
    scanf("%d %d", &n, &k);
    dfs(1, 0, 0);
    printf("%d\n", cnt);
    return 0;
}