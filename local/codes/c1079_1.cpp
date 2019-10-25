/*************************************************************
 *  > File Name        : c1079_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/25 13:01:11
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 310;

int n, m, a[maxn], b[maxn * maxn];
bool vis[maxn * maxn];
int ans[maxn][maxn], ansi;

void solve(int x) {
    memset(vis, 0, sizeof(vis));
    if ((b[1] + b[2] + b[x]) % 2 != 0) return;
    a[1] = (b[2] + b[x] + b[1]) / 2 - b[x];
    a[2] = b[1] - a[1];
    a[3] = b[2] - a[1];
    vis[1] = vis[2] = vis[x] = true;
    for (int ida = 4; ida <= n; ++ida) {
        int idb = 3;
        while (idb <= m && vis[idb]) ++idb;
        if (idb > m) return;
        a[ida] = b[idb] - a[1];
        vis[idb] = true;
        for (int idc = 2; idc < ida; ++idc) {
            if (a[idc] > a[ida]) return;
            int v = a[idc] + a[ida];
            int p = lower_bound(b + 1, b + 1 + m, v) - b;
            if (b[p] != v) return;
            int px = p;
            while (px && b[px] == b[p]) px--; px++;
            while (px <= m && b[px] == b[p] && vis[px]) px++;
            if (b[px] != b[p] || vis[px]) return;
            p = px;
            vis[p] = true; 
        }
    }
    ansi++;
    for (int i = 1; i <= n; ++i) {
        ans[ansi][i] = a[i];
        a[i] = 0;
    }
}

int main() {
    n = read(); m = n * (n - 1) / 2;
    for (int i = 1; i <= m; ++i) b[i] = read();
    sort(b + 1, b + 1 + m);
    for (int i = 3; i <= m;) {
        solve(i);
        int j = i;
        while (j <= m && b[j] == b[i]) ++j;
        i = j;
    }
    printf("%d\n", ansi);
    for (int i = 1; i <= ansi; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}