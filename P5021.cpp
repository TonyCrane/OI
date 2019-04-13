/*************************************************************
 *  > File Name        : P5021.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月11日 星期四 12时59分06秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int inf  = 0x3f3f3f3f;
const int maxn = 50010;

int n, m;
LL dis;

struct Edge {
	int from, to, val;
	Edge(int u, int v, int w) : from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
	edges.push_back(Edge(u, v, w));
	edges.push_back(Edge(v, u, w));
	int mm = edges.size();
	G[u].push_back(mm - 2);
	G[v].push_back(mm - 1);
}

LL dfs1(int x, int fa) {
	LL res1 = 0, res2 = 0;
	for (int i = 0; i < G[x].size(); ++i) {
		Edge& e = edges[G[x][i]];
		if (e.to == fa) continue;
		res2 = max(res2, dfs1(e.to, x) + e.val);
		if (res2 > res1) swap(res1, res2);
	}
	dis = max(dis, res1 + res2);
	return res1;
}

LL dfs(int u, int fa, LL& len, LL lim) {
	int ans = 0;
	multiset<long long> s;
	printf("size: %d\n", G[u].size());
	for (int i = 0; i < G[u].size(); ++i) {
		Edge& e = edges[G[u][i]];
		printf("e.to: %d\n", e.to);
		if (e.to == fa) {
			LL res = 0;
			ans += dfs(e.to, u, res, lim);
			res += e.val;
			if (res >= lim) {
				ans++;
			} else {
				s.insert(res);
			}
		}
	}
	len = 0;
	while (!s.empty()) {
		LL res = *s.begin();
		s.erase(s.begin());
		multiset<long long>::iterator it = s.lower_bound(lim - res);
		if (it != s.end()) {
			s.erase(it);
			ans++;
		} else {
			len = max(len, res);
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; ++i) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		add(a, b, l);
	}
	dfs1(1, 0);
	LL l = 0, r = dis + 1, mid;
	while (r - l > 1) {
		mid = l + r >> 1;
		LL res = 0;
		printf("dfs: %lld\n", dfs(1, 0, res, mid));
		if (dfs(1, 0, res, mid) >= m) {
			l = mid;
		} else {
			r = mid;
		}
	}
	printf("%lld\n", l);
	return 0;
}
