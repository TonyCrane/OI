#include<bits/stdc++.h>
using namespace std;

list<int> lis;
typedef list<int>::iterator Iter;
int n, m, k, p;

int main()
{
	scanf("%d", &n);
	lis.push_back(1);
	for (int i = 2; i <= n; ++i)
	{
		scanf("%d %d", &k, &p);
		if (p == 0)
		{
			Iter it = find(lis.begin(), lis.end(), k);
			lis.insert(it, i);
		}
		else
		{
			Iter it = find(lis.begin(), lis.end(), k);
			it++;
			lis.insert(it, i);
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &k);
		lis.remove(k);
	}
	bool fir = true;
	for (Iter iter = lis.begin(); iter != lis.end(); ++iter)
	{
		if (!fir) printf(" ");
		fir = false;
		printf("%d", *iter); 
	}
	printf("\n");
	return 0;
} 
