/*************************************************************
 *  > File Name        : P3959.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/03 15:17:46
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int inf  = 0x3f3f3f3f;

int vis[20], dis[20], num[20];
int c[20][20], G[20][20];
int ans = inf, tmp, tot, cnt, n, m, p;

bool cmp(int a, int b) {
    return c[p][a] < c[p][b];
}

void dfs(int u, int node) {
    for (int i = u; i <= cnt; ++i) {
        if(tot + tmp * dis[vis[i]] >= ans) return;
        for (int j = node; j <= num[vis[i]]; ++j) {
            if(!dis[G[vis[i]][j]]) {
                cnt++;
                vis[cnt] = G[vis[i]][j];
                tmp -= c[vis[cnt]][G[vis[cnt]][1]];
                tot += c[vis[i]][vis[cnt]] * dis[vis[i]];
                dis[vis[cnt]] = dis[vis[i]] + 1;
                dfs(i, j + 1);
                tot -= c[vis[i]][vis[cnt]] * dis[vis[i]];
                dis[vis[cnt]] = 0;
                tmp += c[vis[cnt]][G[vis[cnt]][1]];
                cnt--;
            }
        }
        node = 1;
    }
    if(cnt == n) {
        if(tot < ans) ans = tot;
        return;
    }
}

int main() {
    int u, v, w;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            c[i][j] = inf;
        }
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        if(c[u][v] < w) continue;
        if(c[u][v] == inf) {
            G[u][++num[u]] = v;
            G[v][++num[v]] = u;
        }
        c[u][v] = c[v][u] = w;
    }
    for (int i = 1; i <= n; ++i) {
        p = i;
        sort(G[i] + 1, G[i] + 1 + num[i], cmp);
        tmp += c[i][G[i][1]];
    }
    for (int i = 1; i <= n; ++i) {
        tot = 0; cnt = 1;
        vis[1] = i;
        tmp -= c[i][G[i][1]];
        dis[i] = 1; 
        dfs(1, 1);
        dis[i] = 0;
        tmp += c[i][G[i][1]];
    }
    printf("%d", ans);
    return 0;
}