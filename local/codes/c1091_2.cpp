/*************************************************************
 *  > File Name        : c1091_2.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/14 13:32:52
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 100010;

int n, deg[maxn], fa[maxn], val[maxn], ans[maxn << 1], leaf = 0;
vector<int> G[maxn];
vector<int> require;

bool cmp(int a, int b) {
	return val[a] > val[b];
}

void dfs(int u, int f) {
	fa[u] = f;
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if (v == f) continue;
		dfs(v, u);
	}
}

void dfs2(int u, int f) {
	ans[++ans[0]] = u;
	vector<int> son;
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if (v == f) continue;
		son.push_back(v);
	}
	sort(son.begin(), son.end(), cmp);
	for (int i = 0; i < son.size(); ++i) {
		dfs2(son[i], u);
		ans[++ans[0]] = u;
	}
}

bool check() {
	int now = 0;
	for (int i = 1; i <= ans[0]; ++i) {
		if (ans[i] == require[now]) now++;
	}
	if (now >= require.size()) return true;
	return false;
}

int main() {
	n = read();
	for (int i = 1; i < n; ++i) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for (int i = 2; i <= n; ++i) if (deg[i] == 1) leaf++;
	dfs(1, 0);
	for (int i = leaf; i; --i) {
		int u = read();
		require.push_back(u);
		while (u) {
			val[u] = i;
			u = fa[u];
		}
	}
	dfs2(1, 0);
	if (check()) {
		for (int i = 1; i <= ans[0]; ++i) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	} else printf("-1\n");
	return 0;
}
