/*************************************************************
 *  > File Name        : P1029.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月16日 星期六 19时42分04秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int x, y, ans;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= sqrt(x * y); ++i)
		if ((x * y) % i == 0 && gcd(i, (x * y) / i) == x)
			ans++;
	printf("%d\n", ans * 2);
	return 0;
}
