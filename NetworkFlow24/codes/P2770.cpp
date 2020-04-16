/*************************************************************
 *  > File Name        : P2770.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/16 07:42:43
 *  > Algorithm        : 最大费用最大流
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 210;
const int inf  = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;

int n, m, s, t, ansflow;
int vis[maxn], d[maxn], p[maxn], a[maxn];
long long anscost;

struct Edge {
	int from, to, cap, flow, cost;
	Edge(int u, int v, int c, int f, int w): from(u), to(v), cap(c), flow(f), cost(w){}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int c, int w) {
	edges.push_back(Edge(u, v, c, 0, w));
	edges.push_back(Edge(v, u, 0, 0,-w));
	int mm = edges.size();
	G[u].push_back(mm - 2);
	G[v].push_back(mm - 1);
}

bool BellmanFord(int& flow, long long& cost) {
    memset(d, 0xc0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	d[s] = 0; vis[s] = 1; p[s] = 0; a[s] = inf;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vis[x] = 0;
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (e.cap > e.flow && d[e.to] < d[x] + e.cost) {
				d[e.to] = d[x] + e.cost;
				p[e.to] = G[x][i];
				a[e.to] = min(a[x], e.cap - e.flow);
				if (!vis[e.to]) {
					Q.push(e.to);
					vis[e.to] = 1;
				}
			}
		}
	}
	if (d[t] == ninf) return false;
	flow += a[t];
	cost += (long long)d[t] * (long long)a[t];
	for (int u = t; u != s; u = edges[p[u]].from) {
		edges[p[u]].flow += a[t];
		edges[p[u] ^ 1].flow -= a[t];
	}
	return true;
}

int MinCostMaxFlow(long long& cost) {
	int flow = 0; cost = 0;
	while (BellmanFord(flow, cost));
	return flow;
}

string name[maxn];
map<string, int> id;

void dfs1(int u) {
    vis[u] = true;
    cout << name[u - n] << endl;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to <= n && e.cap == e.flow) {
            dfs1(e.to + n);
            break;
        }
    }
}

void dfs2(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to <= n && e.cap == e.flow && !vis[e.to + n]) {
            dfs2(e.to + n);
        }
    }
    cout << name[u - n] << endl;
}


int main() {
    n = read(); m = read();
    s = 1; t = 2 * n;
    for (int i = 1; i <= n; ++i) {
        cin >> name[i];
        id[name[i]] = i;
    }
    for (int i = 1; i <= m; ++i) {
        string str1, str2;
        cin >> str1;
        cin >> str2;
        int u = id[str1], v = id[str2];
        if (u > v) swap(u, v);
        add(u + n, v, 1, 0);
    }
    for (int i = 2; i < n; ++i) {
        add(i, i + n, 1, 1);
    }
    add(s, s + n, 2, 1); add(n, t, 2, 1);
    int maxflow = MinCostMaxFlow(anscost);
    if (maxflow == 2) {
        printf("%lld\n", anscost - 2);
    } else if (maxflow == 1) {
        printf("2\n");
        cout << name[1] << "\n" << name[n] << "\n" << name[1] << endl;
        return 0;
    } else {
        printf("No Solution!\n");
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    dfs1(1 + n);
    dfs2(1 + n);
    return 0;
}
