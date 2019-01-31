/*************************************************************
 *  > File Name        : P1478.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/01/29 16:33:15
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int n, s, a, b, x[5010], y[5010], dp[5010];

int main()
{
    scanf("%d %d", &n, &s);
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = s; j >= y[i]; --j)
            if (x[i] <= a + b)
                dp[j] = max(dp[j - y[i]] + 1, dp[j]);
    printf("%d\n", dp[s]);
    return 0;
}