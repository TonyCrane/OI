/*************************************************************
 *  > Description      : 复赛相关模板
 *  > File Name        : JLOI2020_rp++.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/12/12 12:20:39
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

/*-------------------------------- 数论 --------------------------------*/

/* FFT */

const int maxn = 2100010;
const double PI = acos(-1.0);

int cnt, rev[maxn], lim = 1;

struct Complex {
    double r, i;
    Complex() { r = 0, i = 0; }
    Complex(double real, double imag): r(real), i(imag) {}
}F[maxn], G[maxn];
Complex operator + (Complex a, Complex b) { return Complex(a.r + b.r, a.i + b.i); }
Complex operator - (Complex a, Complex b) { return Complex(a.r - b.r, a.i - b.i); }
Complex operator * (Complex a, Complex b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }

void FFT(Complex* A, int opt) {
    for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int s = 1; s <= log2(lim); ++s) {
        int m = 1 << s;
        Complex wn = Complex(cos(2 * PI / m), opt * sin(2 * PI / m));
        for (int k = 0; k < lim; k += m) {
            Complex w = Complex(1, 0);
            for (int j = 0; j < m / 2; ++j) {
                Complex t = w * A[k + j + m / 2];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + m / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (opt == -1) for (int i = 0; i < lim; ++i) F[i].r /= lim;
}


/* NTT */
const int mod  = 998244353;
const int g = 3, invg = 332748118;

int rev[maxn], lim = 1, cnt;
LL F[maxn], G[maxn];

LL pow_mod(LL a, LL p, LL n){
    int res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
}

void NTT(LL* A, int opt) {
    for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int s = 1; s <= log2(lim); ++s) {
        int m = 1 << s; LL wn;
        if (opt == 1) wn = pow_mod(g, (mod - 1) / m, mod);
        else wn = pow_mod(invg, (mod - 1) / m, mod);
        for (int k = 0; k < lim; k += m) {
            LL w = 1;
            for (int j = 0; j < m / 2; ++j) {
                LL t = w * (LL)A[k + j + m / 2] % mod;
                LL u = A[k + j];
                A[k + j] = (u + t) % mod;
                A[k + j + m / 2] = (u - t + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if (opt == -1) {
        LL inv = pow_mod(lim, mod - 2, mod);
        for (int i = 0; i < lim; ++i) A[i] = A[i] * inv % mod;
    }
}



/*-------------------------------- 数据结构 --------------------------------*/

/* 线性基 */
int n;
LL a[maxn], p[64];
bool flag = true;  // 全能插入,则为true,有插入失败的,则为false

bool insert(LL x) {
    for (int i = 61; i >= 0; --i) {
        if (x & (1LL << i)) {
            if (p[i]) x ^= p[i];
            else {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

LL queryMax() {
    LL ans = 0;
    for (int i = 61; i >= 0; --i) {
        if ((ans ^ p[i]) > ans) {
            ans ^= p[i];
        }
    }
    return ans;
}

LL queryMin() {
    if (!flag) return 0LL;
    for (int i = 0; i <= 61; ++i) {
        if (p[i]) return p[i];
    }
}

LL queryKth(LL k) { // 第k小
    if (k == 1LL && !flag) return 0;
    if (!flag) k--;
    for (int i = 1; i <= 61; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (p[i] & (1LL << (j - 1))) p[i] ^= p[j - 1];
        }
    }
    LL ans = 0;
    for (int i = 0; i <= 61; ++i) {
        if (d[i] != 0) {
            if (k & 1) ans ^= p[i];
            k /= 2;
        }
    }
    return ans;
}



/*-------------------------------- 网络流 --------------------------------*/

/* Dinic */
int n, m, s, t, d[maxn], cur[maxn];
struct Edge {
    int from, to, cap, flow;
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int from, int to, int cap) {
    edges.push_back((Edge) {from, to, cap, 0});
    edges.push_back((Edge) {to, from, 0, 0});
    int mm = edges.size();
    G[from].push_back(mm - 2);
    G[to].push_back(mm - 1);
}
bool vis[maxn];
bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
        int x = Q.front(); Q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!vis[e.to] && e.cap > e.flow) {
                vis[e.to] = 1;
                d[e.to] = d[x] + 1;
                Q.push(e.to);
            }
        }
    }
    return vis[t];
}
int DFS(int x, int a) {
    if (x == t || a == 0) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
            e.flow += f;
            edges[G[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;
            if (a == 0) break;
        }
    }
    return flow;
}
int dinic(int s, int t) {
    int flow = 0;
    while (BFS()) {
        memset(cur, 0, sizeof(cur));
        flow += DFS(s, inf);
    }
    return flow;
}

/* 最小费用最大流 */
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
	for (int i = 1; i <= n; ++i) d[i] = inf;
	memset(vis, 0, sizeof(vis));
	d[s] = 0; vis[s] = 1; p[s] = 0; a[s] = inf;
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vis[x] = 0;
		for (int i = 0; i < G[x].size(); ++i) {
			Edge& e = edges[G[x][i]];
			if (e.cap > e.flow && d[e.to] > d[x] + e.cost) {
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
	if (d[t] == inf) return false;
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

/* HLPP */
struct Edge {
    int from, to, cap;
    Edge(int f, int t, int c): from(f), to(t), cap(c) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int f, int t, int c) {
    edges.push_back(Edge(f, t, c));
    edges.push_back(Edge(t, f, 0));
    int mm = edges.size();
    G[t].push_back(mm - 1);
    G[f].push_back(mm - 2);
}
struct Node {
    int id, e, h;
    Node() {}
    Node(int i, int e, int h): id(i), e(e), h(h) {}
    bool operator < (const Node& a) const {
        return h < a.h;
    }
}node[maxn];
priority_queue<Node> pq;

int n, m, s, t;
int vis[maxn], gap[maxn << 1];

queue<int> q;
bool bfs() {
    for (int i = 0; i <= n; ++i)
        node[i].h = inf;
    node[t].h = 0; q.push(t);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (edges[G[u][i] ^ 1].cap && node[e.to].h > node[u].h + 1) {
                node[e.to].h = node[u].h + 1;
                q.push(e.to);
            }
        }
    }
    return node[s].h != inf;
}
void push(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if ((e.cap) && (node[e.to].h + 1 == node[u].h)) {
            int df = min(node[u].e, e.cap);
            e.cap -= df; edges[G[u][i] ^ 1].cap += df;
            node[u].e -= df; node[e.to].e += df;
            if ((e.to != s) && (e.to != t) && (!vis[e.to])) {
                pq.push(Node(e.to, node[e.to].e, node[e.to].h));
                vis[e.to] = 1;
            }
            if (!node[u].e) break;
        }
    }
}
void relabel(int u) {
    node[u].h = inf;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if ((e.cap) && (node[e.to].h + 1 < node[u].h)) node[u].h = node[e.to].h + 1;
    }
}
int HLPP() {
    if (!bfs()) return 0;
    node[s].h = n;
    memset(gap, 9, sizeof(int) * (n << 1));
    for (int i = 1; i <= n; ++i)
        if (node[i].h != inf) gap[node[i].h]++;
    for (int i = 0; i < G[s].size(); ++i) {
        Edge& e = edges[G[s][i]];
        if (int f = e.cap) {
            e.cap -= f; edges[G[s][i] ^ 1].cap += f;
            node[s].e -= f; node[e.to].e += f;
            if (e.to != s && e.to != t && !vis[e.to]) {
                pq.push(Node(e.to, node[e.to].e, node[e.to].h));
                vis[e.to] = 1;
            }
        }
    }
    while (!pq.empty()) {
        Node top = pq.top(); pq.pop(); int u = top.id;
        vis[u] = 0; push(u);
        if (node[u].e) {
            if (!--gap[node[u].h]) {
                for (int v = 1; v <= n; ++v) {
                    if (v != s && v != t && node[v].h > node[u].h && node[v].h < n + 1) {
                        node[v].h = n + 1;
                    }
                }
            }
            relabel(u); gap[node[u].h]++;
            pq.push(Node(u, node[u].e, node[u].h)); vis[u] = 1;
        }
    }
    return node[t].e;
}