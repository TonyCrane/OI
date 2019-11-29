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
    
}

bool isSub2 = false, isSub3 = true;

void init() {
    for (int i = 1; i <= n; ++i) {
        id[i] = read();
        val[id[i]] = i;
    }
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++; deg[v]++;
        if (deg[u] == n - 1 || deg[v] == n - 1) isSub2 = true;
        if (deg[u] > 2 || deg[v] > 2) isSub3 = false; 
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
    }
    return 0;
}