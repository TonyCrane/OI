#include<bits/stdc++.h>
using namespace std;

int n;
char S[1200];

char func(int l, int r)
{
	int mid = (l + r) / 2;
	char c1, c2, c3;
	if (l == r)
	{
		if (S[l] == '0') c3 = 'B';
		else c3 = 'I';
	}
	else
	{
		c1 = func(l, mid);
		c2 = func(mid + 1, r);
		if (c1 == 'B' && c2 == 'B') c3 = 'B';
		else if (c1 == 'I' && c2 == 'I') c3 = 'I';
		else c3 = 'F';
	}
	printf("%c", c3);
	return c3;
}

int main()
{
	scanf("%d", &n);
	scanf("%s", S + 1);
	func(1, pow(2, n));
	return 0;
}
