/*************************************************************
 *  > File Name        : c1067_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 15:22:36
 *  > Algorithm        : 不会
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

const int maxn = 100010;

struct Edge {
    int from, to;
    Edge(int u, int v): from(u), to(v) {}
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back(Edge(u, v));
    int mm = edges.size();
    G[u].push_back(mm - 1);
}

int n, siz[maxn], son[maxn], ufs[maxn], Son, ds[maxn];
bool vis[maxn];
LL ans, AnsOut, AnsIn;
set<int> s;

LL calc(LL x) {
    return x * (x - 1) / 2;
}

void clear() {
    s.clear();
    s.insert(0);
    s.insert(n + 1);
    AnsOut = calc(n);
    AnsIn = 0;
}

void dfs1(int x, int fa) {
    siz[x] = 1;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa) continue;
        dfs1(e.to, x);
        siz[x] += siz[e.to];
        if (siz[e.to] > siz[son[x]]) {
            son[x] = e.to;
        }
    }
}

int find(int x) {
    return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}

void upd(int x, int fa) {
    s.insert(x);
    set<int>::iterator s1, s2, it;
    s1 = s2 = it = s.find(x);
    s1--; s2++;
    AnsOut -= calc(*s2 - *s1 - 1);
    AnsOut += calc(*s2 - *it - 1) + calc(*it - *s1 - 1);
    vis[x] = true;
    if (vis[x - 1]) {
        int fx = find(x - 1);
        int fy = find(x);
        AnsIn += ds[fx] * ds[fy];
        ufs[fx] = fy;
        ds[fy] += ds[fx];
    }
    if (vis[x + 1]) {
        int fx = find(x + 1);
        int fy = find(x);
        AnsIn += ds[fx] * ds[fy];
        ufs[fx] = fy;
        ds[fy] += ds[fx];
    }
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa || e.to == Son) continue;
        upd(e.to, x);
    }
}

void del(int x, int fa) {
    vis[x] = false;
    ds[x] = 1; ufs[x] = x;
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa) continue;
        del(e.to, x);
    }
}

void dfs2(int x, int fa, bool opt) {
    for (int i = 0; i < G[x].size(); ++i) {
        Edge& e = edges[G[x][i]];
        if (e.to == fa || e.to == son[x]) continue;
        dfs2(e.to, x, false);
    }
    if (son[x]) {
        dfs2(son[x], x, true);
        Son = son[x];
    }
    upd(x, fa);
    ans += calc(n) - AnsIn - AnsOut;
    if (!opt) {
        del(x, fa);
        clear();
        Son = 0;
    }
}


int main() {
    n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v); add(v, u);
    }
    for (int i = 1; i <= n; ++i) {
        ufs[i] = i;
        ds[i] = 1;
    }
    dfs1(1, 0);
    clear();
    dfs2(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}