/*************************************************************
 *  > File Name        : P1081.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/11 20:55:35
 *  > Algorithm        : 毒瘤倍增
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

struct Node { int h, id; bool operator < (const Node& a) const { return h < a.h; } }a[maxn];
set<Node> S; set<Node>::iterator it; LL f[maxn][21][2];
int n, m, nex[maxn][2], dis[maxn][2], G[maxn][21], x0;

inline void update(Node x, Node y) {
    if (!nex[x.id][0]) { nex[x.id][0] = y.id; dis[x.id][0] = abs(x.h - y.h); }
    else if (abs(x.h - y.h) < dis[x.id][0] || (abs(x.h - y.h) == dis[x.id][0] && y.h < a[nex[x.id][0]].h))
    { nex[x.id][1] = nex[x.id][0]; dis[x.id][1] = dis[x.id][0]; nex[x.id][0] = y.id; dis[x.id][0] = abs(x.h - y.h); }
    else if (abs(x.h - y.h) < dis[x.id][1] || (abs(x.h - y.h) == dis[x.id][1] && y.h < a[nex[x.id][1]].h))
    { nex[x.id][1] = y.id; dis[x.id][1] = abs(x.h - y.h); }
    else if (!nex[x.id][1]) { nex[x.id][1] = y.id; dis[x.id][1] = abs(x.h - y.h); }
}

inline void query(int s, int x, LL& disa, LL& disb) {
    for (int i = 20; i >= 0; --i) if(f[s][i][0] + f[s][i][1] <= x && G[s][i])
    { disa += f[s][i][0]; disb += f[s][i][1]; x -= f[s][i][0] + f[s][i][1]; s = G[s][i]; }
    if (nex[s][1] && dis[s][1] <= x) disa += dis[s][1];
}

int main() {
    n = read(); for (int i = 1; i <= n; ++i) { a[i].h = read(); a[i].id = i; }
    for (int i = n; i; --i) { S.insert(a[i]); it = S.find(a[i]); if (it != S.begin()) {
        it--; update(a[i], *it); if (it != S.begin()) { it--; update(a[i], *it); it++; } it++; }
        if ((++it) != S.end()) { update(a[i], *it); if ((++it) != S.end()) update(a[i], *it); it--; } it--; }
    for (int i = 1; i <= n; ++i) { G[i][0] = nex[nex[i][1]][0]; f[i][0][0] = dis[i][1]; f[i][0][1] = dis[nex[i][1]][0]; }
    for (int j = 1; j <= 20; ++j) for (int i = 1; i <= n; ++i) { G[i][j] = G[G[i][j - 1]][j - 1]; 
        f[i][j][0] = f[i][j - 1][0] + f[G[i][j - 1]][j - 1][0]; f[i][j][1] = f[i][j - 1][1] + f[G[i][j - 1]][j - 1][1]; }
    x0 = read(); int s0 = 0; LL a = 0x7f7f7f7f, b = 0;
    for (int i = 1; i <= n; ++i) { LL disa = 0, disb = 0; query(i, x0, disa, disb); if (disb && (!s0 || a * disb > b * disa))
    { s0 = i; a = disa; b = disb; } } printf("%d\n", s0);
    m = read(); while (m--) { int s = read(), x = read(); LL disa = 0, disb = 0; query(s, x, disa, disb); 
    printf("%lld %lld\n", disa, disb); } return 0;
}