/*************************************************************
 *  > File Name        : c1064_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/03 16:05:13
 *  > Algorithm        : ufs
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

long long ans = 0;
int n, m, a[maxn], ufs[maxn];
vector<int> G[maxn];

inline int find(int x) {
    return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
}

inline void unionn(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        ufs[fx] = fy;
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        ufs[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        unionn(x, y);
    }
    if (n < 2 * (n - m - 1)) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        G[find(i)].push_back(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (G[i].empty()) continue;
        sort(G[i].begin(), G[i].end());
        ans += G[i][0];
        for (int j = 1; j < G[i].size(); ++j) {
            G[0].push_back(G[i][j]);
        }
    }
    sort(G[0].begin(), G[0].end());
    for (int i = 0; i < n - m - 2; ++i) {
        ans += G[0][i];
    }
    printf("%lld\n", ans);
    return 0;
}