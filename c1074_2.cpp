/*************************************************************
 *  > File Name        : c1074_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/12 16:38:06
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

const int maxn = 110;
const int mod  = 1e9 + 7;

vector<int> G[maxn];
struct Node {
    int val, dep;
};

int n, m, k, ans[maxn], now[maxn];
bool vis[maxn];

void bfs(int s) {
    queue<Node> q;
    q.push((Node){s, 0}); vis[s] = 1;
    while (!q.empty()) {
        Node top = q.front(); q.pop();
        int u = top.val, dep = top.dep;
        vis[u] = 0;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            now[v]++;
            if (dep + 1 == k) {
                ans[v] += now[u];
                ans[v] %= mod;
                continue;
            }
            if (!vis[v]) {
                q.push((Node){v, dep + 1});
                vis[v] = 1;
            }
        }
    }
}

int main() {
    n = read(); m = read(); k = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
    }
    bfs(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i] % mod);
    }
    return 0;
}