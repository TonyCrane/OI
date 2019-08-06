/*************************************************************
 *  > File Name        : P2279.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/05 16:05:23
 *  > Algorithm        : [Greedy]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1020;

int n, ans;
int pos[maxn], fa[maxn], dis[maxn], val[maxn];

bool cmp(int x, int y) {
    return dis[x] > dis[y];
}

int main() {
    scanf("%d", &n);
    pos[1] = 1;
    memset(val, 0x3f, sizeof(val));
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &fa[i]);
        dis[i] = dis[fa[i]] + 1;
        pos[i] = i;
    }
    sort(pos + 1, pos + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        int v = pos[i];
        int w = fa[v];
        int u = fa[w];
        val[v] = min(val[v], min(val[w] + 1, val[u] + 2));
        if (val[v] > 2) {
            val[u] = 0;
            ans++;
            val[fa[u]] = min(val[fa[u]], 1);
            val[fa[fa[u]]] = min(val[fa[fa[u]]], 2);
        }
    }
    printf("%d\n", ans);
    return 0;
}