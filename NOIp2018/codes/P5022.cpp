/*************************************************************
 *  > File Name        : P5022.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月13日 星期六 15时48分38秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5050;
const int inf  = 0x3f3f3f3f;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
	return x * f;
}

int n, m, ans[maxn], in[maxn][2];

vector<int> G[maxn];

namespace SolveOne {
	int cnt = 0;
	bool vis[maxn];
	void dfs(int u, int fa) {
		ans[++cnt] = u;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if (!vis[v]) {
				dfs(v, u);
			}
		}
	}
	void solve() {
		for (int i = 1; i <= n; ++i) {
			sort(G[i].begin(), G[i].end());
		}
		dfs(1, 0);
		for (int i = 1; i <= n; ++i) {
			printf("%d ", ans[i]);
		}
	}
}

namespace SolveTwo {
	int cnt = 0, res[maxn], du, dv;
	bool vis[maxn];
	bool notdel(int u, int v) {
		if ((u == du && v == dv) || (u == dv && v == du)) {
			return false;
		}
		return true;
	}
	void dfs(int u, int fa) {
		res[++cnt] = u;
		vis[u] = true;
		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if (!vis[v] && notdel(u, v)) {
				dfs(v, u);
			}
		}
	}
	bool judge() {
		for (int i = 1; i <= n; ++i) {
			if (ans[i] != res[i]) {
				return ans[i] > res[i];
			}
		}
		return false;
	}
	void solve() {
		memset(ans, 0x3f, sizeof(ans));
		for (int i = 1; i <= n; ++i) {
			sort(G[i].begin(), G[i].end());
		}
		for (int i = 1; i <= m; ++i) {
			cnt = 0;
			memset(res, 0, sizeof(res));
			memset(vis, 0, sizeof(vis));
			du = in[i][0];
			dv = in[i][1];
			dfs(1, 0);
			if (judge() && cnt == n) {
				memcpy(ans, res, sizeof(res));
			}
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d ", ans[i]);
		}
	}
}

int main() {
	n = read(); m = read();
	for (int i = 1; i <= m; ++i) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
		in[i][0] = u;
		in[i][1] = v;
	}
	if (m == n - 1) {
		SolveOne::solve();
	} else {
		SolveTwo::solve();
	}
	return 0;
}
