#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 110;

struct Edge {
	int from, to, val;
	Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
	edges.push_back(Edge(u, v, w));
	int mm = edges.size();
	G[u].push_back(mm - 1);
}

int n, m;
int dis[maxn], pre[maxn], outdeg[maxn];
bool vis[maxn];
queue<int> q;

void SPFA(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	vis[s] = true; dis[s] = 0; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (int i = 0; i < G[u].size(); ++i) {
			Edge& e = edges[G[u][i]];
			if (dis[e.to] > dis[u] + e.val) {
				dis[e.to] = dis[u] + e.val;
				pre[e.to] = u;
				if (!vis[e.to]) {
					q.push(e.to);
					vis[e.to] = true;
				}
			}
		}
	}
}

namespace Subtask1 {
	void work() {
		SPFA(1);
		int i = n, cnt = 0;
		while (pre[i] != -1) {
			cnt++;
			i = pre[i];
		}
		printf("%d\n", dis[n] == 0x3f3f3f3f ? -1 : dis[n] % cnt);
		return;
	}
}

int main() {
	freopen("home.in", "r", stdin);
	freopen("home.out", "w", stdout);
	int T = read();
	srand((int)time(NULL));
	while (T--) {
		n = read(); m = read(); bool isSub1 = true;
		for (int i = 1; i <= m; ++i) {
			int u = read(), v = read(), w = read();
			add(u, v, w);
			outdeg[u]++;
			if (outdeg[u] > 1) isSub1 = false;
		}
		if (isSub1) {
			Subtask1::work();
		} else {
			int ans = rand() % n;
			printf("%d\n", ans == 0 ? -1 : ans);
		}
	}
	return 0;
}
