/*************************************************************
 *  > Description      : 连通分量系列模板
 *  > File Name        : tarjan.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/09/02 12:57:56
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

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

namespace Bridge {

    int dfn[maxn], low[maxn], n, m, num;
    bool bridge[maxn << 1];

    void tarjan(int x, int in_edge) {
        dfn[x] = low[x] = ++num;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to, i);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] > dfn[x]) {
                    bridge[i] = bridge[i ^ 1] = true;
                }
            } else if (i != (in_edge ^ 1)) {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i, 0);
            }
        }
        for (int i = 0; i < edges.size(); i += 2) {
            if (bridge[i]) {
                /* ... */
            }
        }
        return 0;
    }

}

namespace CutPoint {

    int dfn[maxn], low[maxn], n, m, num, root;
    bool cut[maxn];

    void tarjan(int x) {
        dfn[x] = low[x] = ++num;
        int flag = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] >= dfn[x]) {
                    flag++;
                    if (x != root || flag > 1) cut[x] = true;
                }
            } else {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) {
                /* ... */
            }
        }
        return 0;
    }

}

namespace e_DCC {

    using namespace Bridge;
    int c[maxn], dcc;
    
    void dfs(int x) {
        c[x] = dcc;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (c[e.to] || bridge[i]) continue;
            dfs(e.to);
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i, 0);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!c[i]) {
                ++dcc;
                dfs(i);
            }
        }
        /** 
         * 共dcc个边双连通分量
         * 点x属于第c[x]个边双连通分量
         **/
        return 0;
    }

}

namespace e_DCC_ShrinkPoint {

    using namespace e_DCC;
    vector<Edge> nedges;
    vector<int> nG[maxn];
    void nadd(int u, int v) {
        nedges.push_back(Edge(u, v));
        int mm = nedges.size();
        nG[u].push_back(mm - 1);
    }

    int ShrinkPoint() {
        for (int i = 0; i < edges.size(); ++i) {
            Edge& e1 = edges[i];
            Edge& e2 = edges[i ^ 1];
            if (c[e1.to] == c[e2.to]) continue;
            nadd(c[e1.to], c[e2.to]);
        }
    }

}

namespace v_DCC {

    bool cut[maxn];
    int dfn[maxn], low[maxn], n, m, num, root;
    vector<int> dcc[maxn]; int cnt;
    stack<int> s;

    void tarjan(int x) {
        dfn[x] = low[x] = ++num; s.push(x);
        if (x == root && G[x].empty()) {
            dcc[++cnt].push_back(x);
            return;
        }
        int flag = 0;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
                if (low[e.to] >= dfn[x]) {
                    flag++; cnt++; int z;
                    if (x != root || flag > 1) cut[x] = true;
                    do {
                        z = s.top(); s.pop();
                        dcc[cnt].push_back(z);
                    } while (z != e.to);
                    dcc[cnt].push_back(x);
                }
            } else {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v); add(v, u);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                root = i;
                tarjan(i);
            }
        }
        /**
         * 共cnt个点双连通分量
         * 每个v-DCC存储在dcc[i]中
         **/
        return 0;
    }

}

namespace v_DCC_ShrinkPoint {

    using namespace v_DCC;
    vector<Edge> nedges;
    vector<int> nG[maxn];
    void nadd(int u, int v) {
        nedges.push_back(Edge(u, v));
        int mm = nedges.size();
        nG[u].push_back(mm - 1);
    }

    int new_id[maxn], c[maxn];

    int ShrinkPoint() {
        num = cnt;
        for (int i = 1; i <= n; ++i) {
            if (cut[i]) {
                new_id[i] = ++num;
            }
        }
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 0; j < dcc[i].size(); ++j) {
                int x = dcc[i][j];
                if (cut[x]) {
                    nadd(i, new_id[x]);
                    nadd(new_id[x], i);
                } else {
                    c[x] = i;
                }
            }
        }
    }

}

namespace SCC {

    int dfn[maxn], low[maxn], c[maxn];
    int val[maxn], sum[maxn], n, m, num, cnt;
    stack<int> s; bool ins[maxn];
    vector<int> scc[maxn];

    void tarjan(int x) {
        dfn[x] = low[x] = ++num; s.push(x); ins[x] = true;
        for (int i = 0; i < G[x].size(); ++i) {
            Edge& e = edges[G[x][i]];
            if (!dfn[e.to]) {
                tarjan(e.to);
                low[x] = min(low[x], low[e.to]);
            } else if (ins[e.to]) {
                low[x] = min(low[x], dfn[e.to]);
            }
        }
        if (dfn[x] == low[x]) {
            cnt++; int y;
            do {
                y = s.top(); s.pop(); ins[y] = false;
                c[y] = cnt; scc[cnt].push_back(y);
                sum[cnt] += val[y];
            } while (x != y);
        }
    }

    int main() {
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            add(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        /**
         * 共cnt个强连通分量
         * x所在的SCC编号为c[x]
         * 编号为i的强连通分量所有点为scc[i]
         **/
        return 0;
    }

}

namespace SCC_ShrinkPoint {

    using namespace SCC;
    vector<Edge> nedges;
    vector<int> nG[maxn];
    void nadd(int u, int v) {
        nedges.push_back(Edge(u, v));
        int mm = nedges.size();
        nG[u].push_back(mm - 1);
    }

    int ShrinkPoint() {
        for (int x = 1; x <= n; ++x) {
            for (int i = 0; i < G[x].size(); ++i) {
                Edge& e = edges[G[x][i]];
                if (c[x] == c[e.to]) continue;
                nadd(c[x], c[e.to]);
            }
        }
    }

}