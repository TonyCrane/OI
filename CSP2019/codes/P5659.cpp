/*************************************************************
 *  > File Name        : P5659.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/28 16:07:38
 *  > Algorithm        : tree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2010;

int n, deg[maxn], val[maxn], id[maxn];

vector<int> G[maxn];

namespace Subtask1 { // 10分 n!暴力
    int id[maxn], Val[maxn], del[maxn], val[maxn], ans[maxn], res[maxn];
    struct Edge {
        int u, v;
    }edges[maxn];
    bool better() {
        for (int i = 1; i <= n; ++i) if (ans[i] != res[i]) 
            return res[i] < ans[i];
        return false;
    }
    void work() {
        memset(ans, 0, sizeof(ans));
        memset(edges, 0, sizeof(edges));
        memset(Val, 0, sizeof(Val));
        for (int i = 1; i <= n; ++i) Val[read()] = i;
        for (int i = 1; i < n; ++i) edges[i] = (Edge){read(), read()};
        for (int i = 1; i < n; ++i) del[i] = i;
        do {
            for (int i = 1; i <= n; ++i) val[i] = Val[i];
            for (int i = 1; i < n; ++i) swap(val[edges[del[i]].u], val[edges[del[i]].v]);
            for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) 
                if (val[j] == i) { res[i] = j; break; }
            if (ans[1] == 0) memcpy(ans, res, sizeof(ans));
            if (better()) memcpy(ans, res, sizeof(ans));
        } while (next_permutation(del + 1, del + n));
        for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
        puts("");
        return;
    }
}

namespace Subtask2 { // 25分 菊花图
    bool vis[maxn];
    int ans[maxn], ufs[maxn];
    int find(int x) { return x == ufs[x] ? x : ufs[x] = find(ufs[x]); }
    void work() {
        for (int i = 1; i <= n; ++i) ufs[i] = i;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < n; ++i) for (int j = 1; j <= n; ++j) {
            if (!vis[j] && find(val[i]) != find(j)) {
                vis[j] = true; ans[val[i]] = j;
                ufs[find(val[i])] = find(j); break;
            }
        }
        for (int i = 1; i < n; ++i) printf("%d ", ans[val[i]]);
        for (int i = 1; i <= n; ++i) if (!vis[i]) printf("%d\n", i);
        return;
    }
}

namespace Subtask3 { // 25分 链
    bool vis[maxn];
    int lid[maxn], lst[maxn], cnt = 0, mrk[maxn], ans[maxn];
    void init() {
        memset(mrk, 0, sizeof(mrk));
        memset(vis, 0, sizeof(vis));
        cnt = 0;
    }
    void dfs(int u, int fa) {
        lid[u] = ++cnt;
        lst[cnt] = u;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            if (v == fa) continue;
            dfs(v, u);
        }
    }
    bool check_l(int u, int v) {
        u = lid[u], v = lid[v];
        if (mrk[u] == 1 || mrk[v] == 1) return false;
        for (int i = u + 1; i <= v - 1; ++i) if (mrk[i] == 2) return false;
        return true;
    }
    bool check_r(int u, int v) {
        u = lid[u], v = lid[v];
        if (mrk[u] == 2 || mrk[v] == 2) return false;
        for (int i = v + 1; i <= u - 1; ++i) if (mrk[i] == 1) return false;
        return true; 
    }
    void mark_l(int u, int v) {
        u = lid[u], v = lid[v];
        if (u != 1 && u != n) mrk[u] = 2;
        if (v != 1 && v != n) mrk[v] = 2;
        for (int i = u + 1; i <= v - 1; ++i) mrk[i] = 1;
    }
    void mark_r(int u, int v) {
        u = lid[u], v = lid[v];
        if (u != 1 && u != n) mrk[u] = 1;
        if (v != 1 && v != n) mrk[v] = 1;
        for (int i = v + 1; i <= u - 1; ++i) mrk[i] = 2;
    }
    void work() {
        init();
        for (int i = 1; i <= n; ++i) if (deg[i] == 1) {
            dfs(i, 0);
            break;
        }
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
            if (!vis[j] && lid[id[i]] != lid[j]) {
                int u = id[i], v = j;
                bool valid = false;
                if (lid[u] <= lid[v]) {
                    if (check_l(u, v)) {
                        mark_l(u, v);
                        valid = true;
                    }
                } else if (check_r(u, v)) {
                    mark_r(u, v);
                    valid = true;
                }
                if (valid) { ans[i] = j; vis[j] = true; break; }
            }
        }
        for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
        puts("");
        return;
    }
}

bool isSub2 = false, isSub3 = true;

void init() {
    for (int i = 1; i <= n; ++i) {
        id[i] = read();
        val[id[i]] = i;
    }
    memset(deg, 0, sizeof(deg));
    isSub2 = false; isSub3 = true;
    for (int i = 0; i <= maxn - 1; ++i) G[i].clear();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++; deg[v]++;
        if (deg[u] == n - 1 || deg[v] == n - 1) isSub2 = true;
        if (deg[u] > 2 || deg[v] > 2) isSub3 = false; 
    }
}


namespace Fullmark { // 100分 正解
    struct Edge {
        int from, to;
        Edge(int u, int v): from(u), to(v) {}
    };
    vector<Edge> edges;
    vector<int> G[maxn];
    void add(int u, int v) {
        edges.push_back(Edge(u, v));
        edges.push_back(Edge(v, u));
        int mm = edges.size();
        G[v].push_back(mm - 1);
        G[u].push_back(mm - 2);
        deg[u]++; deg[v]++;
    }
    const int s = 4020, t = 6030;
    int ufs[maxn * 3 + 10], pre[maxn * 3 + 10], suf[maxn * 3 + 10];
    int siz[maxn * 3 + 10], res;
    int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
    bool check(int a, int b, int u) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        if (suf[a] || pre[b]) return false;
        if (fa == find(s + u) && fb == find(t + u) && siz[fa] + siz[fb] < deg[u]) return false;
        return true;
    }
    void unionn(int a, int b) {
        suf[a] = b; pre[b] = a;
        a = find(a); b = find(b);
        ufs[a] = b;
        siz[b] += siz[a];
    }
    void dfs1(int u, int edge) {
        if (check(edge, t + u, u)) res = min(res, u);
        if (suf[edge]) {
            int v = edges[suf[edge]].to;
            dfs1(v, suf[edge] ^ 1);
        } else for (int i = 0; i < G[u].size(); ++i) {
            if (G[u][i] == edge) continue;
            int v = edges[G[u][i]].to;
            if (check(edge, i, u)) dfs1(v, i ^ 1);
        }
    }
    bool ok = false;
    void dfs2(int u, int edge) {
        if (u == res) {
            ok = true;
            unionn(edge, t + u);
            return;
        }
        if (suf[edge]) {
            int v = edges[suf[edge]].to;
            dfs2(v, suf[edge] ^ 1);
        } else for (int i = 0; i < G[u].size(); ++i) {
            if (G[u][i] == edge) continue;
            int v = edges[G[u][i]].to;
            if (check(edge, i, u)) {
                dfs2(v, i ^ 1);
                if (ok) { unionn(edge, i); return; }
            }
        }
    }
    void init() {
        edges.clear();
        for (int i = 0; i < maxn; ++i) G[i].clear();
        memset(pre, 0, sizeof(pre));
        memset(suf, 0, sizeof(suf));
        memset(deg, 0, sizeof(deg));
        memset(siz, 0, sizeof(siz));
        for (int i = 0; i < maxn; ++i) ufs[i] = i;
    }
    void work() {
        init();
        n = read();
        for (int i = 1; i <= n; ++i) id[i] = read();
        for (int i = 1; i <  n; ++i) {
            int u = read(), v = read();
            add(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            res = n + 1;
            dfs1(id[i], s + id[i]);
            printf("%d ", res);
            ok = false;
            dfs2(id[i], s + id[i]);
        }
        puts("");
    }
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        if (n <= 10) { Subtask1::work(); continue; }
        init();
        if (isSub2) Subtask2::work();
        else if (isSub3) Subtask3::work();
        // Fullmark::work();
    }
    return 0;
}