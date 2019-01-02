#include<bits/stdc++.h>
using namespace std;

list<int> lis;
typedef list<int>::iterator Iter;
int n, m, k, p;
Iter pos[100010];
bool erased[100010];

int main()
{
	scanf("%d", &n);
	lis.push_back(1);
	pos[1] = lis.begin();
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d %d", &k, &p);
		if (p == 0)
		{
			pos[i] = lis.insert(pos[k], i);
		}
		else
		{
			Iter nextIter = next(pos[k]);
			pos[i] = lis.insert(nextIter, i);
		}
	}
	scanf("%d", &m);
	for (int x, i = 1; i <= m; ++i)
	{
		scanf("%d", &x);
		if (!erased[x])
		{
			lis.erase(pos[x]);
		}
		erased[x] = true;
	}
	bool first = true;
	for (int i: lis)
	{
		if (!first)
		{
			printf(" ");
		}
		first = false;
		printf("%d", i);
	}
	printf("\n");
	return 0;
} 
