/*************************************************************
 *  > File Name        : 1130.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/08 17:29:18
 *  > Algorithm        : DP
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
const int mod  = 1000000007;

struct Edge {
    int from, to;
};
vector<Edge> edges;
vector<int> G[maxn];
void add(int u, int v) {
    edges.push_back((Edge){u, v});
    edges.push_back((Edge){v, u});
    int mm = edges.size();
    G[v].push_back(mm - 1);
    G[u].push_back(mm - 2);
}

int n, a[maxn];
LL dp[maxn][2];

void DP(int u, int fa) {
    dp[u][a[u]] = 1;
    for (int i = 0; i < G[u].size(); ++i) {
        Edge& e = edges[G[u][i]];
        if (e.to != fa) {
            DP(e.to, u);
            dp[u][1] = ( dp[u][1] * dp[e.to][1] + dp[u][1] * dp[e.to][0] + dp[u][0] * dp[e.to][1] ) % mod;
            dp[u][0] = ( dp[u][0] * dp[e.to][1] + dp[u][0] * dp[e.to][0] ) % mod;
        }
    }
}

int main() {
    n = read();
    for (int i = 1; i < n; ++i) {
        int j = read();
        add(i, j);
    }
    for (int i = 0; i < n; ++i) a[i] = read();
    DP(0, -1);
    printf("%lld\n", dp[0][1]);
    return 0;
}