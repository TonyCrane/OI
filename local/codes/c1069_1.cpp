/*************************************************************
 *  > File Name        : c1069_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/25 14:56:21
 *  > Algorithm        : dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 5010;

int ans[maxn], k, m;
bool vis[maxn];

bool dfs(int now, int dep) {
    if (vis[now]) return false;
    vis[now] = true;
    ans[dep] = now & 1;
    if (dep == m - 1) return true;
    if (dfs((now << 1) & (m - 1), dep + 1)) return true;
    if (dfs((now << 1 | 1) & (m - 1), dep + 1)) return true;
    vis[now] = false;
    return false;
}

int main() {
    k = read();
    m = 1 << k;
    printf("%d ", m);
    dfs(0, 0);
    for (int i = 1; i <= k; ++i) {
        printf("0");
    }
    for (int i = 1; i <= m - k; ++i) {
        printf("%d", ans[i]);
    }
    return 0;
}