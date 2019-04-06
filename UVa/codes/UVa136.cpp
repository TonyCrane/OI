/*************************************************************
 *  > File Name        : UVa136.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/02/06 14:37:41
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int coeff[3] = {2, 3, 5};

int main()
{
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1; ; ++i)
    {
        LL x = pq.top(); pq.pop();
        if (i == 1500)
        {
            printf("The 1500'th ugly number is %lld.\n", x);
            break;
        }
        for (int j = 0; j < 3; ++j)
        {
            LL x2 = x * coeff[j];
            if (!s.count(x2))
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    return 0;
}