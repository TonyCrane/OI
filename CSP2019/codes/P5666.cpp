/*************************************************************
 *  > File Name        : P5666.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/28 15:16:14
 *  > Algorithm        : centroid
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 300000;

vector<int> G[maxn];

int n;
int son1[maxn], son2[maxn], son3[maxn];
int siz1[maxn], siz2[maxn];
int pre[maxn], f[maxn], p[maxn][20];
long long ans;

void dfs1(int u, int fa) {
    siz1[u] = 1; pre[u] = fa; f[u] = fa;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (v == fa) continue;
        dfs1(v, u);
        siz1[u] += siz1[v];
        if (siz1[v] > siz1[son1[u]]) {
            son2[u] = son1[u];
            son1[u] = v;
        } else if (siz1[v] > siz1[son2[u]]) {
            son2[u] = v;
        }
    }
    p[u][0] = son1[u]; siz2[u] = siz1[u]; son3[u] = son1[u];
    for (int i = 1; i <= 17; ++i) p[u][i] = p[p[u][i - 1]][i - 1];
}

int valid(int u, int tot) {
    if (max(siz2[son3[u]], tot - siz2[u]) <= tot / 2) return u;
    else return 0;
}

void dfs2(int u, int fa) {
    for (int i = 0; i< G[u].size(); ++i) {
        int v = G[u][i];
        if (v == fa) continue;
        f[u] = f[v] = 0;
        siz2[u] = siz1[1] - siz1[v];

        if (son1[u] == v) son3[u] = son2[u];
        else son3[u] = son1[u];
        if (siz2[fa] > siz2[son3[u]]) son3[u] = fa;
        p[u][0] = son3[u];
        for (int i = 1; i <= 17; ++i) 
            p[u][i] = p[p[u][i - 1]][i - 1];
        
        int now = u;
        for (int i = 17; i; --i) {
            if (siz2[u] - siz2[p[now][i]] <= siz2[u] / 2)
                now = p[now][i];
        }
        ans += valid(son3[now], siz2[u]);
        ans += valid(now, siz2[u]);
        ans += valid(f[now], siz2[u]);

        now = v;
        for (int i = 17; i; --i) {
            if (siz2[v] - siz2[p[now][i]] <= siz2[v] / 2)
                now = p[now][i];
        }
        ans += valid(son3[now], siz2[v]);
        ans += valid(now, siz2[v]);
        ans += valid(f[now], siz2[v]);
        
        f[u] = v;
        dfs2(v, u);
    }
    son3[u] = son1[u]; f[u] = pre[u];
    p[u][0] = son1[u]; siz2[u] = siz1[u];
    for (int i = 1; i <= 17; ++i)
        p[u][i] = p[p[u][i - 1]][i - 1];
}

void init() {
    for (int i = 0; i <= maxn - 1; ++i) G[i].clear(); ans = 0;
    memset(son1, 0, sizeof(son1));
    memset(son2, 0, sizeof(son2));
}

int main() {
    int T = read();
    while (T--) {
        init();
        n = read();
        for (int i = 1; i < n; ++i) {
            int u = read(), v = read();
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs1(1, 0);
        dfs2(1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}