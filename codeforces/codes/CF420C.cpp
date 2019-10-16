/*************************************************************
 *  > File Name        : CF420C.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/16 21:24:39
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

const int maxn = 2000010;

int deg[maxn], n, p;
map<pair<int, int>, int> G;

int main() {
    n = read(); p = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read();
        if (x > y) swap(x, y);
        G[pair<int, int>(x, y)]++;
        deg[x]++; deg[y]++;
    }
    long long ans = 0;
    for (map<pair<int, int>, int>::iterator it = G.begin(); it != G.end(); ++it) {
        int x = it->first.first;
        int y = it->first.second;
        if (deg[x] + deg[y] >= p && deg[x] + deg[y] - it->second < p) ans--;
    }
    sort(deg + 1, deg + 1 + n);
    int now = n;
    for (int i = 1; i <= n; ++i) {
        while (now > i && deg[now] + deg[i] >= p) now--;
        ans += n - max(now, i);
    }
    printf("%lld\n", ans);
    return 0;
}