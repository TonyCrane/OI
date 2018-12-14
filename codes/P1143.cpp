#include<bits/stdc++.h>
using namespace std;

int n, m, e, k, sum, ans;
int c[10000000];
char str[1000000000];

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	scanf("%d", &m);
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] < 'A')
		{
			e = pow(n, strlen(str) - i - 1);
			e *= str[i] - '0';
			sum += e;
		}
		else
		{
			e = pow(n, strlen(str) - i - 1);
			e *= str[i] - 'A' + 10;
			sum += e;
		}
	}
	while (sum > 0)
	{
		c[k++] = sum % m;
		sum /= m;
	}
	for (int i = k - 1; i >= 0; --i)
	{
		if (c[i] >= 10) printf("%c", c[i] + 'A' - 10);
		else printf("%d", c[i]);
	}
	return 0;
}
