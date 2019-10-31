/*************************************************************
 *  > File Name        : P3574.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/31 21:21:49
 *  > Algorithm        : greedy+tree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500010;

vector<int> G[maxn];
void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

int n, c[maxn], son[maxn], f[maxn], siz[maxn];

bool cmp(int a, int b) {
    return siz[a] - f[a] < siz[b] - f[b];
}

void dfs(int u, int fa) {
    if (u != 1) f[u] = c[u];
    for (int i = 0; i < G[u].size(); ++i) {
        int& v = G[u][i];
        if (v != fa) dfs(v, u);
    }
    int cnt = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        int& v = G[u][i];
        if (v != fa) son[++cnt] = v;
    }
    sort(son + 1, son + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; ++i) {
        f[u] = max(f[u], f[son[i]] + siz[u] + 1);
        siz[u] += siz[son[i]] + 2;
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) c[i] = read();
    for (int i = 1; i <  n; ++i) {
        int u = read(), v = read();
        add(u, v);
    }
    dfs(1, 0);
    printf("%d\n", max(f[1], siz[1] + c[1]));
    return 0;
}