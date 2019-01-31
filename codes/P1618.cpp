/*************************************************************
 *  > File Name        : P1618.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/01/29 16:52:18
**************************************************************/

#include<bits/stdc++.h>
using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int A, B, C, h;

int main()
{
    scanf("%d %d %d", &A, &B, &C);
    int t = A * B * C;
    A = t / A;
    B = t / B;
    C = t / C;
    do
    {
        if((100 * a[1] + 10 * a[2] + a[3]) * A == (100 * a[4] + 10 * a[5] + a[6]) * B && (100 * a[1] + 10 * a[2] + a[3]) * A == (100 * a[7] + 10 * a[8] + a[9]) * C)
        {
            printf("%d%d%d %d%d%d %d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
            h++;
        }
    }while (next_permutation(a + 1, a + 10));
    if (h == 0)
        printf("No!!!\n");
    return 0;
}