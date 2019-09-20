/*************************************************************
 *  > File Name        : c1067_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/19 15:22:36
 *  > Algorithm        : 不会
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

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

int n, deg[maxn];
long long ans;

namespace Subtask1 {
    int head, chain[maxn], cnt;
    bool vis[maxn];
    void dfs(int u, int id) {
        vis[u] = 1; chain[id] = u;
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (vis[e.to]) continue;
            dfs(e.to, id + 1);
        }
    }
    int tree(int l, int r) {
        int fir, las;
        for (int i = 1; i <= n; ++i) {
            if (l <= chain[i] && chain[i] <= r) {
                fir = i;
                break;
            }
        }
        for (int i = n; i >= 1; --i) {
            if (l <= chain[i] && chain[i] <= r) {
                las = i;
                break;
            }
        }
        return las - fir;
    }
    void work() {
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) {
                head = i;
                break;
            }
        }
        dfs(head, 1);
        for (int l = 1; l <= n; ++l) {
            for (int r = l + 1; r <= n; ++r) {
                ans += (long long)tree(l, r);
            }
        }
        printf("%lld\n", ans);
    }
}

namespace Subtask2 {
    int f[3010][20], d[maxn], LCA[3010][3010];
    int t; bool vis[maxn];
    void bfs(int s) {
        t = (int)(log(n) / log(2)) + 1;
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
    int pre[maxn];
    void dfs(int u, int fa) {
        for (int i = 0; i < G[u].size(); ++i) {
            Edge& e = edges[G[u][i]];
            if (e.to == fa) continue;
            pre[e.to] = G[u][i];
            dfs(e.to, u);
        }
    }
    long long tree(int l, int r) {
        int fa = LCA[l][r];
        long long res = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = l; i <= r; ++i) {
            int now = i;
            while (now != fa) {
                if (!vis[pre[now]]) {
                    res++;
                    vis[pre[now]] = true;
                }
                now = f[now][0];
            }
        }
        return res;
    }
    void work() {
        dfs(1, 0); bfs(1);
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (j == i + 1) LCA[i][j] = lca(i, j);
                else LCA[i][j] = lca(LCA[i][j - 1], j);
            }
        }
        for (int l = 1; l <= n; ++l) {
            for (int r = l + 1; r <= n; ++r) {
                ans += tree(l, r);
            }
        }
        printf("%lld\n", ans);
    }  
}

namespace Subtask3 {
    int dep[maxn], siz[maxn], fa[maxn], son[maxn], top[maxn];
    int clock = 0, dfn[maxn];
    void dfs1(int x, int f, int depth) {
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
    void dfs2(int x, int topf) {
        top[x] = topf; dfn[x] = ++clock;
        if (!son[x]) return;
        dfs2(son[x], topf);
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (e.to == fa[x] || e.to == son[x]) continue;
            dfs2(e.to, e.to);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        return x;
    }
    bool cmp(int i, int j) {
        return dfn[i] < dfn[j];
    }

    int id[maxn], sr[maxn], sl[maxn];
    int l[maxn], r[maxn], tl[maxn], tr[maxn];

    void work() {
        dfs1(1, 0, 1);
        dfs2(1, 1);
        for (int i = 1; i <= n; ++i) {
            ans += 1LL * (1LL * (i - 1) * (n - i + 1) + n - i) * dep[i];
            id[i] = i;
        }
        sort(id + 1, id + 1 + n, cmp);
        sr[0] = id[1]; sl[n + 1] = id[n]; id[n + 1] = n + 1;
        for (int i = 1; i <= n; ++i) {
            sl[id[i]] = id[i - 1];
            sr[id[i]] = id[i + 1];
        }
        for (int i = 1; i < n; ++i) {
            memset(tl, 0, sizeof(tl));
            memset(tr, 0, sizeof(tr));
            memcpy(l, sl, sizeof(sl));
            memcpy(r, sr, sizeof(sr));
            for (int j = n, T = 1, L, R; j > i; --j, ++T) {
                int a, b;
                if ((L = l[j]) == 0) {
                    a = j;
                    b = l[n + 1];
                } else {
                    a = j;
                    b = L;
                }
                int tmp = min(T - tr[b], T - tl[a]);
                ans -= 1LL * tmp * dep[lca(a, b)];
                tr[b] = T;
                if ((R = r[j]) == n + 1) {
                    b = j;
                    a = r[0];
                } else {
                    b = j;
                    a = R;
                }
                tmp = min(T - tr[b], T - tl[a]);
                ans -= 1LL * tmp * dep[lca(a, b)];
                tl[a] = T;
                r[L] = R; l[R] = L;
            }
            sr[sl[i]] = sr[i];
            sl[sr[i]] = sl[i];
        }
        printf("%lld\n", ans);
    }
}


int main() {
    n = read();
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        add(u, v); add(v, u);
        deg[u]++; deg[v]++;
    }
    if (n <= 300) {
        Subtask3::work();
    } else {
        Subtask3::work();
    }
    return 0;
}