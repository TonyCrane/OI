/*************************************************************
 *  > File Name        : P5021.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019年04月11日 星期四 12时59分06秒
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

void read(int& x) {
	x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + ch - 48; ch = getchar();}
}

const int maxn = 50050;
const int inf  = 0x3f3f3f3f;

int n, m, cnt, num, s[maxn], mid;

struct Edge {
	int from, to, val;
	Edge(int u, int v, int w) : from(u), to(v), val(w) {}
};
vector<Edge> G[maxn];
void add(int u, int v, int w) {
	G[u].push_back(Edge(u, v, w));
	G[v].push_back(Edge(v, u, w));
}

int dfs(int u, int fa) {
	priority_queue<int> lh;
	priority_queue<int, vector<int>, greater<int> > sh;
	int ln = 0, sn = 1;
	for (int i = 0; i < G[u].size(); ++i) {
		if (G[u][i].to != fa) {
			int d = G[u][i].val + dfs(G[u][i].to, u);
			sh.push(d); lh.push(d);
			ln++;
		}
	}
	while (ln > 0 && lh.top() >= mid) {num++; lh.pop(); ln--;}
	int now = 0;
	while (ln > sn) {
		if (u != 1 && lh.top() + sh.top() >= mid) {
			int cnt = 0;
			while (ln > sn && lh.top() + sh.top() >= mid) {s[++cnt] = lh.top(); lh.pop(); ln--;}
			num++; sh.pop(); sn++;
			while (cnt > 1) {lh.push(s[--cnt]); ln++;}
		} else if (u == 1 && lh.top() + sh.top() >= mid) {
			lh.pop(); sh.pop(); ln--; sn++; num++;
		} else {
			now = sh.top(); sh.pop(); sn++;
		}
		if (num >= m) break;
	}
	if (ln >= sn && !lh.empty()) return lh.top();
	else return now;
}

bool check() {
	num = 0;
	dfs(1, 0);
	if (num >= m) return true;
	else return false;
}

int main() {
	read(n); read(m); int all = 0;
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		read(u); read(v); read(w);
		add(u, v, w);
		all += w;
	}
	int l = 0, r = all / m, ans = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check()) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
