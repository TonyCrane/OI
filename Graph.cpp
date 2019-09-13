/*************************************************************
 *  > Description      : 图论模板
 *  > File Name        : Graph.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/01 14:04:05
 *  > Copyright (C) 2019 Tony
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
const int maxn = 10010;
const int inf  = 0x3f3f3f3f;


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

namespace Dijkstra_heap 
{

    struct heap {
        int u, d;
        bool operator < (const heap& a) const {
            return d > a.d;
        }
    };
    int n, m, dis[maxn];
    void Dijkstra(int s) {
        priority_queue<heap> q;
        memset(dis, 0x3f, sizeof(dis));
        dis[s] = 0;
        q.push((heap){s, 0});
        while (!q.empty()) {
            heap top = q.top(); q.pop();
            int u = top.u, td = top.d;
            if (td != dis[u]) continue;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (dis[e.to] > dis[u] + e.val) {
                    dis[e.to] = dis[u] + e.val;
                    q.push((heap){e.to, dis[e.to]});
                }
            }
        }
    }

}

namespace SPFA
{

    int dis[maxn];
    bool vis[maxn];
    void SPFA(int s) {
        memset(dis, 0x3f, sizeof(dis));
        dis[s] = 0; vis[s] = true;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = false;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (dis[e.to] > dis[u] + e.val) {
                    dis[e.to] = dis[u] + e.val;
                    if (!vis[e.to]) {
                        q.push(e.to);
                        vis[e.to] = true;
                    }
                }
            }
        }
    }

}

namespace SPFA_SLF
{

    int dis[maxn];
    bool vis[maxn];
    void SPFA(int s) {
        memset(dis, 0x3f, sizeof(dis));
        deque<int> q; q.push_back(s);
        dis[s] = 0; vis[s] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop_front(); 
            vis[u] = false;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (dis[e.to] > dis[u] + e.val) {
                    dis[e.to] = dis[u] + e.val;
                    if (!vis[e.to]) {
                        vis[e.to] = true;
                        if (!q.empty() && dis[e.to] < dis[q.front()]) {
                            q.push_front(e.to);
                        } else {
                            q.push_back(e.to);
                        }
                    }
                }
            }
        }
    }

}

namespace Floyd
{

    int G[maxn][maxn], dis[maxn][maxn], n;
    void Floyd()
    {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dis[i][j] = G[i][j];
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    dis[i][j] = min(dis[i][j], dis[i][k], dis[k][j]);
    }

}

namespace Kruskal
{

    bool cmp(Edge a, Edge b) {
        if (a.val != b.val) return a.val < b.val;
        if (a.from != b.from) return a.from < b.from;
        return a.to < b.to;
    }
    int ufs[maxn], n, m, ans = 0, cnt = 1;
    inline int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
    void Kruskal() {
        for (int i = 1; i <= n; ++i) ufs[i] = i;
        sort(edges.begin(), edges.end(), cmp);
        for (int i = 0; i < m; ++i) {
            Edge& e = edges[i];
            int x = find(e.from), y = find(e.to);
            if (x != y) {
                ufs[x] = y;
                ans += e.val;
                cnt++;
            }
        }
    }

}

namespace Tree
{

    namespace dfs
    {

        int a[maxn], cnt; bool vis[maxn];
        vector<int> son[maxn];
        void dfs(int x) {
            a[++cnt] = x;
            vis[x] = true;
            for (int i = 0; i < son[x].size(); ++i) {
                int y = son[x][i];
                if (vis[y]) continue;
                dfs(y);
            }
            a[++cnt] = x;
        }

    }

    namespace dep
    {

        bool vis[maxn]; int dep[maxn];
        vector<int> son[maxn];
        void dfs(int x) {
            vis[x] = true;
            for (int i = 0; i < son[x].size(); ++i) {
                int y = son[x][i];
                if (vis[y]) continue;
                dep[y] = dep[x] + 1;
                dfs(y);
            }
        }

    }

    namespace center
    {

        bool vis[maxn]; int size[maxn], n, ans, pos;
        vector<int> son[maxn];
        void dfs(int x) {
            vis[x] = true; size[x] = 1;
            int max_part = 0;
            for (int i = 0; i < son[x].size(); ++i) {
                int y = son[x][i];
                if (vis[y]) continue;
                dfs(y);
                size[x] += size[y];
                max_part = max(max_part, size[y]);
            }
            max_part = max(max_part, n - size[x]);
            if (max_part < ans) {
                ans = max_part; 
                pos = x;
            }
        }

    }

    namespace diameter
    {

        int ans;
        int dfs(int x) {
            int res1 = 0, res2 = 0;
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                res2 = max(res2, dfs(e.to) + e.val);
                if (res2 > res1) swap(res1, res2);
            }
            ans = max(ans, res1 + res2);
            return res1;
        }

    }

    namespace TreeChainSplit
    {

        int n, m, r, mod, cnt, res, w[maxn], wt[maxn];
        int son[maxn], id[maxn], fa[maxn], dep[maxn], siz[maxn], top[maxn];


        /* SegmentTree */
        struct SegmentTreeNode {
            int l, r, len;
            int dat, laz;
            #define l(p) tree[p].l
            #define r(p) tree[p].r
            #define len(p) tree[p].len
            #define dat(p) tree[p].dat
            #define laz(p) tree[p].laz
        }tree[maxn << 2];

        inline void pushup(int p) {
            dat(p) = (dat(p<<1) + dat(p<<1|1)) % mod;
        }

        inline void pushdown(int p) {
            laz(p<<1) += laz(p);
            laz(p<<1|1) += laz(p);
            dat(p<<1) += laz(p) * (len(p) - (len(p) >> 1));
            dat(p<<1|1) += laz(p) * (len(p) >> 1);
            dat(p<<1) %= mod;
            dat(p<<1|1) %= mod;
            laz(p) = 0;
        }

        inline void build(int p, int l, int r) {
            l(p) = l, r(p) = r;
            len(p) = r - l + 1;
            if (l == r) {
                dat(p) = wt[l] % mod;
                return;
            }
            int mid = (l + r) >> 1;
            build(p<<1, l, mid);
            build(p<<1|1, mid + 1, r);
            pushup(p);
        }

        inline void query(int p, int l, int r) {
            if (l <= l(p) && r(p) <= r) {
                res += dat(p);
                res %= mod;
                return;
            }
            if (laz(p)) pushdown(p);
            int mid = (l(p) + r(p)) >> 1;
            if (l <= mid) query(p<<1, l, r);
            if (r >  mid) query(p<<1|1, l, r);
        }

        inline void update(int p, int l, int r, int k) {
            if (l <= l(p) && r(p) <= r) {
                laz(p) += k;
                dat(p) += k * len(p);
                return;
            }
            if (laz(p)) pushdown(p);
            int mid = (l(p) + r(p)) >> 1;
            if (l <= mid) update(p<<1, l, r, k);
            if (r >  mid) update(p<<1|1, l, r, k);
            pushup(p);
        }


        /* Tree Chain Split */
        inline void dfs1(int x, int f, int depth) {
            dep[x] = depth; fa[x] = f;
            siz[x] = 1; int maxs = -1;
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (e.to == f) continue;
                dfs1(e.to, x, depth + 1);
                siz[x] += siz[e.to];
                if (siz[e.to] > maxs) {
                    son[x] = e.to;
                    maxs = siz[e.to];
                }
            }
        }

        inline void dfs2(int x, int topf) {
            id[x] = ++cnt;
            wt[id[x]] = w[x];
            top[x] = topf;
            if (!son[x]) return;
            dfs2(son[x], topf);
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (e.to == fa[x] || e.to == son[x]) continue;
                dfs2(e.to, e.to);
            }
        }


        /* Query And Operation */
        inline void updRange(int x, int y, int k) {
            k %= mod;
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                update(1, id[top[x]], id[x], k);
                x = fa[top[x]];
            }
            if (dep[x] > dep[y]) swap(x, y);
            update(1, id[x], id[y], k);
        }

        inline int qRange(int x, int y) {
            int ans = 0;
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                res = 0;
                query(1, id[top[x]], id[x]);
                ans += res; ans %= mod;
                x = fa[top[x]];
            }
            if (dep[x] > dep[y]) swap(x, y);
            res = 0;
            query(1, id[x], id[y]);
            ans += res; ans %= mod;
            return ans;
        }

        inline void updSubtree(int x, int k) {
            update(1, id[x], id[x] + siz[x] - 1, k);
        }

        inline int qSubtree(int x) {
            res = 0;
            query(1, id[x], id[x] + siz[x] - 1);
            return res;
        }

    }

    namespace PointDivideAndConquer 
    {

        int n, m, sum, root, ans;
        int maxp[maxn], size[maxn], dis[maxn], rem[maxn];
        int q[maxn], query[maxn];
        bool vis[maxn], test[maxk], judge[maxk];

        void GetRoot(int u, int fa) {
            size[u] = 1; maxp[u] = 0;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (e.to == fa || vis[e.to]) continue;
                GetRoot(e.to, u);
                size[u] += size[e.to];
                maxp[u] = max(maxp[u], size[e.to]);
            }
            maxp[u] = max(maxp[u], sum - size[u]);
            if (maxp[u] < maxp[root]) root = u;
        }

        void GetDist(int u, int fa) {
            rem[++rem[0]] = dis[u];
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (e.to == fa || vis[e.to]) continue;
                dis[e.to] = dis[u] + e.val;
                GetDist(e.to, u);
            }
        }

        void calc(int u) {
            int p = 0;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (vis[e.to]) continue;
                rem[0] = 0; dis[e.to] = e.val;
                GetDist(e.to, u);
                for (int j = rem[0]; j; --j) {
                    for (int k = 1; k <= m; ++k) {
                        if (query[k] >= rem[j]) {
                            test[k] |= judge[query[k] - rem[j]];
                        }
                    }
                }
                for (int j = rem[0]; j; --j) {
                    q[++p] = rem[j];
                    judge[rem[j]] = true;
                }
            }
            for (int i = 1; i <= p; ++i) {
                judge[q[i]] = false;
            }
        }

        void solve(int u) {
            vis[u] = judge[0] = true;
            calc(u);
            for (int i = 0; i < G[u].size(); ++i) {
                Edge& e = edges[G[u][i]];
                if (vis[e.to]) continue;
                sum = size[e.to]; maxp[root = 0] = maxk;
                GetRoot(e.to, 0); solve(root);
            }
        }

    }

}

namespace LCA
{

    int f[maxn][20], d[maxn];
    int n, m, t;
    void bfs(int s) {
        queue<int> q;
        q.push(s); d[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (d[e.to]) continue;
                d[e.to] = d[x] + 1;
                f[e.to][0] = x;
                for (int j = 1; j <= t; ++j) {
                    f[e.to][j] = f[f[e.to][j - 1]][j - 1];
                }
                q.push(e.to);
            }
        }
    }
    int lca(int x, int y) {
        if (d[x] > d[y]) swap(x, y);
        for (int i = t; i >= 0; --i) {
            if (d[f[y][i]] >= d[x]) y = f[y][i];
        }
        if (x == y) return x;
        for (int i = t; i >= 0; --i) {
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
            }
        }
        return f[x][0];
    }
    int Main() {
        t = (int)(log(n) / log(2)) + 1;
    }

}

namespace Tarjan_cut
{

    bool cut[maxn];
    int n, m, num, root, ansi;
    int dfn[maxn], low[maxn], s[maxn], ans[maxn];
    void tarjan(int x) {
        dfn[x] = low[x] = ++num; int flag = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] >= dfn[x]) {
                    flag++;
                    if (x != root || flag > 1) {
                        cut[x] = true;
                    }
                }
            } else {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }
    int Main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read(), w = read();
            if (u == v) continue;
            add(u, v, w); add(v, u, w);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i);
            }
        }
        /* ... */
    }

}

namespace maxflow_Edmonds_Karp
{

    int n, m, s, t, ans;
    struct Edge {
        int from, to, cap, flow;
        Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
    };
    vector<Edge> edges;
    vector<int> G[maxn];
    int a[maxn], p[maxn];
    void add(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        int mm = edges.size();
        G[from].push_back(mm - 2);
        G[to].push_back(mm - 1);
    }
    void EdmondsKarp() {
        ans = 0;
        for (;;) {
            memset(a, 0, sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s] = inf;
            while (!Q.empty()) {
                int x = Q.front(); Q.pop();
                for (int i = 0; i < G[x].size(); ++i) {
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow) {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from) {
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            ans += a[t];
        }
        return;
    }

}

namespace maxflow_Dinic
{

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
    int MaxFlow(int s, int t) {
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, inf);
        }
        return flow;
    }

}

namespace maxflow_ISAP
{

    int n, m, s, t;
    int d[maxn], p[maxn], num[maxn], cur[maxn];
    bool vis[maxn];
    struct Edge {
        int from, to, cap, flow;
        Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f){}
    };
    vector<Edge> edges;
    vector<int> G[maxn];
    void add(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        int mm = edges.size();
        G[from].push_back(mm - 2);
        G[to].push_back(mm - 1);
    }
    void bfs() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(t);
        d[t] = 0; vis[t] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
    }
    int Augment() {
        int x = t, a = inf;
        while (x != s) {
            Edge& e = edges[p[x]];
            a = min(a, e.cap - e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while (x != s) {
            edges[p[x]].flow += a;
            edges[p[x] ^ 1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }
    int ISAP(int s, int t) {
        int flow = 0;
        bfs();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++i) num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while (d[s] < n) {
            if (x == t) {
                flow += Augment();
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (e.cap > e.flow && d[x] == d[e.to] + 1) {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i;
                    x = e.to;
                    break;
                }
            }
            if (!ok) {
                int mm = n - 1;
                for (int i = 0; i < G[x].size(); ++i) {
                    Edge& e = edges[G[x][i]];
                    if (e.cap > e.flow) mm = min(mm, d[e.to]);
                }
                if (--num[d[x]] == 0) break;
                num[d[x] = mm + 1]++;
                cur[x] = 0;
                if (x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }

}

namespace mincost_maxflow
{

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

}