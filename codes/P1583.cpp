#include<bits/stdc++.h>
using namespace std;

int n, k, E[20];

struct Node
{
	int id, w;
}node[20010];

bool cmp(Node a, Node b)
{
	if (a.w == b.w) return a.id < b.id;
	return a.w > b.w;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= 10; ++i) scanf("%d", &E[i]);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &node[i].w);
		node[i].id = i + 1;
	}
	sort(node, node + n, cmp);
	for (int i = 0; i < n; ++i)
		node[i].w += E[i % 10 + 1];
	sort(node, node + n, cmp);
	for (int i = 0; i < k; ++i)
		printf("%d ", node[i].id);
	return 0;
}
