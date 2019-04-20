/*************************************************************
 *  > File Name        : P3958.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月20日 星期六 12时13分19秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

bool fini = false, vis[maxn];
int T, n, h, r;

struct Node {
	double x, y, z;
} node[maxn];

bool cmp(Node a, Node b) {
	return a.z > b.z;
}

double dist(Node a, Node b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

void dfs(Node now, int num) {
	if (now.z + r >= h) {
		fini = true;
		return;
	}
	vis[num] = true;
	for (int i = 1; i <= n; ++i) {
		if (fini) {
			return;
		} else if (!vis[i] && dist(node[i], now) <= r * 2) {
			dfs(node[i], i);
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		fini = false;
		memset(node, 0, sizeof(node));
		memset(vis, 0, sizeof(vis));
		scanf("%d %d %d", &n, &h, &r);
		for (int i = 1; i <= n; ++i) {
			scanf("%lf %lf %lf", &node[i].x, &node[i].y, &node[i].z);
		}
		sort(node + 1, node + 1 + n, cmp);
		for (int i = 1; i <= n; ++i) {
			if (node[i].z - r <= 0) {
				dfs(node[i], i);
			}
		}
		printf(fini ? "Yes\n" : "No\n");
	}
	return 0;
}
