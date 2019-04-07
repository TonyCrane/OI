/*************************************************************
 *  > File Name        : P1579.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/01/29 16:59:35
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int a, i, n1, n2, n3, x;

int judge(int x)
{
    for (i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 1;
    return 0;
}

int main()
{
    scanf("%d", &a);
    for (n1 = 2; n1 <= a - 4; n1++)
    {
        for (n2 = 2; n2 <= a - 4; n2++)
        {
            n3 = a - n1 - n2;
            if (judge(n1) + judge(n2) + judge(n3) != 0)
                continue;
            printf("%d %d %d\n", n1, n2, n3);
            return 0;
        }
    }
}