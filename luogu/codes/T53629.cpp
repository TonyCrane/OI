/*************************************************************
 *  > File Name        : T53629.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/02/08 11:24:38
 *  > Algorithm        : 
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

const int maxn = 5010;
const int maxm = 200010;

int n, m, k, w, d, r, cnt;
LL ans;
int ufs[maxn];
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }

struct edge {
    int f, t, v, b, e, w;
}ed[maxm];
bool cmp(edge a, edge b) { return a.w > b.w; }

struct Edge {
    int from, to, val;
    Edge(int u, int v, int w): from(u), to(v), val(w) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v, int w) {
    edges.push_back(Edge(u, v, w));
    edges.push_back(Edge(v, u, w));
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

void init() {
    edges.clear();
    for (int i = 1; i <= n; ++i) G[i].clear();
    ans = 0; r = read(); cnt = 0;
    for (int i = 1; i <= n; ++i) ufs[i] = i;
}

void Kruskal() {
    sort(ed, ed + m, cmp);
    for (int i = 0; i < m; ++i) {
        edge& e = ed[i];
        if (e.w <= 0) break;
        int x = find(e.f);
        int y = find(e.t);
        if (x != y) {
            ufs[x] = y; cnt++;
            add(e.f, e.t, e.w);
            if (cnt == n - 1) return;
        }
    }
}

void dfs(int u, int fa) {
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to == fa) continue;
        ans += e.val;
        dfs(e.to, u);
    }
}

void getWeight() {
    if (k == 0 && w == 0) {
        for (int i = 0; i < m; ++i) {
            edge& e = ed[i];
            if (r >= e.b && r <= e.e) e.w = e.v;
            else e.w = 0;
        }
        return;
    }
    for (int i = 0; i < m; ++i) {
        edge& e = ed[i];
        if      (r < e.b) e.w = e.v - ceil((double)(e.b - r) / k) * w;
        else if (r > e.e) e.w = e.v - ceil((double)(r - e.e) / k) * w;
        else e.w = e.v;
    }
    // for (int i = 0; i < m; ++i) {
    //     printf("edge#%d : %d %d %d\n", i, ed[i].f, ed[i].t, ed[i].w);
    // }
}

int main() {
    n = read(); m = read(); k = read(); w = read(); d = read();
    for (int i = 0; i < m; ++i) {
        edge& e = ed[i]; e.f = read(); e.t = read(); 
        e.v = read();   e.b = read(); e.e = read();
    }
    while (d--) {
        init();
        getWeight();
        Kruskal();
        dfs(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}