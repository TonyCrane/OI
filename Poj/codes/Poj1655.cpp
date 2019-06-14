/*************************************************************
 *  > File Name        : Poj1655.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/14 12:42:06
 *  > Algorithm        : [Tree]Center
**************************************************************/

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 20010;
const int inf  = 0x3f3f3f3f;

vector<int> G[maxn];

void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool vis[maxn];
int size[maxn];
int ans, center, n;

void dfs(int x) {
    vis[x] = 1; size[x] = 1;
    int max_part = 0;
    for (int i = 0; i < G[x].size(); ++i) {
        int y = G[x][i];
        if (vis[y]) continue;
        dfs(y);
        size[x] += size[y];
        max_part = max(max_part, size[y]);
    }
    max_part = max(max_part, n - size[x]);
    if (max_part < ans) {
        ans = max_part;
        center = x;
    }
}

void init() {
    memset(vis, 0, sizeof(vis));
    memset(size, 0, sizeof(size));
    for (int i = 0; i < maxn - 1; ++i) {
        G[i].clear();
    }
    ans = inf; center = inf;
}

int main() {
    int T = read();
    while (T--) {
        init();
        n = read();
        for (int i = 1; i <= n - 1; ++i) {
            int u = read(), v = read();
            add(u, v);
        }
        dfs(1);
        printf("%d %d\n", center, ans);
    }
    return 0;
}