/*************************************************************
 *  > File Name        : P1192.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/02/01 16:49:55
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int s[100002] = {0}, n, k;

int main()
{
    scanf("%d %d", &n, &k);
    s[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && (i - j) >= 0; j++)
            s[i] += s[i - j];
        s[i] = s[i] % 100003;
    }
    printf("%d", s[n]);
    return 0;
}