/*************************************************************
 *  > File Name        : P5021.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月11日 星期四 12时59分06秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int inf  = 0x3f3f3f3f;
const int maxn = 50010;

int n, m, head[maxn], cnt, ans;

struct Edge {
	int to, nxt, val;
}edges[maxn << 1];

void add(int u, int v, int w) {
	edges[++cnt].to = v;
	edges[cnt].val  = w;
	edges[cnt].nxt  = head[u];
	head[u] = cnt;
}

namespace Meq1 {
	int dfs(int now, int fa) {
		int res1 = 0, res2 = 0;
		for (int i = head[now]; i; i = edges[i].nxt) {
			int to = edges[i].to;
			if (to == fa) continue;
			res2 = max(res2, dfs(to, now) + edges[i].val);
			if (res2 > res1) swap(res1, res2);
		}
		ans = max(ans, res1 + res2);
		return res1;
	}

	void solve() {
		dfs(1, 0);
		printf("%d\n", ans);
		return ;
	}
}

namespace Aeq1 {
	int arr[maxn];
	
	bool cmp(int a, int b) {
		return a > b;
	}

	void solve() {
		for (int i = head[1]; i; i = edges[i].nxt) {
			int to = edges[i].to;
			arr[to - 1] = edges[i].val;
		}
		sort(arr + 1, arr + n, cmp);
		ans = inf;
		for (int i = 1; i <= m; ++i) {
			ans = min(ans, arr[i] + arr[2 * m - i + 1]);
		}
		printf("%d\n", ans);
		return ;
	}
}

namespace OneChain {
	int arr[maxn], ans;

	int Dfs(int now, int fa) {
		int res1 = 0, res2 = 0;
		for (int i = head[now]; i; i = edges[i].nxt) {
			int to = edges[i].to;
			if (to == fa) continue;
			res2 = max(res2, Dfs(to, now) + edges[i].val);
			if (res2 > res1) swap(res1, res2);
		}
		ans = max(ans, res1 + res2);
		return res1;
	}

	void dfs(int now, int fa) {
		for (int i = head[now]; i; i = edges[i].nxt) {
			int to = edges[i].to;
			if (to == fa) continue;
			dfs(to, now);
			arr[now] = edges[i].val;
		}
	}

	bool judge(int x) {
		int t = 0, now = 0;
		for (int i = 1; i < n; ++i) {
			if (now + arr[i] >= x) {
				now = 0;
				t++;
			} else {
				now += arr[i];
			}
		}
		return t >= m;
	}

	void solve() {
		dfs(1, 0);
		Dfs(1, 0);
		int l = 1, r = ans, mid;
		while (l < r) {
			mid = l + r + 1 >> 1;
			if (judge(mid)) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", l);
		return ;
	}
}

int main() {
	bool aie1 = true;
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		add(a, b, l); add(b, a, l);
		if (a != 1) aie1 = false;
	}
	if (m == 1) {
		Meq1::solve();
	} else if (aie1) {
		Aeq1::solve();
	} else {
		OneChain::solve();
	}
	return 0;
}
