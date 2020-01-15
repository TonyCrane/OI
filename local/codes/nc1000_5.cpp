/*************************************************************
 *  > File Name        : pi.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年01月14日 星期一 12时43分19秒
**************************************************************/
 
#include<bits/stdc++.h>
using namespace std;
 
int a, sum;
 
void func(int n)
{
    int x;
    if (n == 0) return;
    for (int i = 0; i <= 15; i++)
    {
        x = i;
        if (pow(2, i) > n)
        {
            x--;
            break;
        }
    }
    if (x == 0) cout<<"2(0)";
    if (x == 1) cout<<"2";
    if (x > 1)
    {
        cout<<"2(";
        func(x);
        cout<<")";
    }
    if (n != pow(2, x))
    {
        cout<<"+";
        func(n - pow(2,x));
    } 
}          
 
int main()
{
    scanf("%d", &a);
    func(a);
    return 0;
}