#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000010;
int p[maxn], cnt, m, n, tmp;
bool vis[maxn], jud[maxn];

void getprime()
{
	for (int i = 2; i <= n; ++i)
	{
		if (!vis[i])
		{
			p[++cnt] = i;
			jud[i] = true;
		}
		for (int j = 1; j <= cnt; ++j)
		{
			int v = i * p[j];
			if (v >= n) break;
			vis[v] = true;
			if (i % p[j] == 0) continue;
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	p[1] = 1;
	getprime();
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &tmp);
		if (!jud[tmp]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
