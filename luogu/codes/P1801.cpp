/*************************************************************
 *  > File Name        : P1801.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月20日 星期三 15时57分24秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int m, n, a[200010], b, r = 1;

priority_queue<int> LH;
priority_queue<int, vector<int>, greater<int> > SH;

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &b);
		for (int j = r; j <= b; ++j)
		{
			LH.push(a[j]);
			if (LH.size() == i)
			{
				SH.push(LH.top());
				LH.pop();
			}
		}
		r = b + 1;
		printf("%d\n", SH.top());
		LH.push(SH.top());
		SH.pop();
	}
	return 0;
}
