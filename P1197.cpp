/*************************************************************
 *  > File Name        : P1197.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/01/29 11:40:53
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int maxn = 500000;

int n, m, xi, yi, ufs[maxn];

int find(int x)
{
    if ( x != ufs[x]) return ufs[x] = find(ufs[x]);
    return ufs[x] = x;
}

void unionn(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        ufs[fx] = fy;
    return;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d %d", &xi, &yi);
        unionn(xi, yi);
    }
    
}