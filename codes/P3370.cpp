/*************************************************************
 *  > File Name        : P3370.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年02月28日 星期四 12时55分16秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
ULL base = 131, a[10010], mod = 212370440130137957LL;
char s[10010];
int n, ans = 1, prime = 233317;

ULL hash(char* s)
{
	int len = strlen(s);
	ULL Ans = 0;
	for (int i = 0; i < len; ++i)
		Ans = (Ans * base + (ULL)s[i]) % mod + prime;
	return Ans;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", s);
		a[i] = hash(s);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; ++i)
	{
		if (a[i] != a[i + 1])
			ans++;
	}
	printf("%d", ans);
}
