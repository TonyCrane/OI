/*************************************************************
 *  > File Name        : P1137.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/22 21:05:18
 *  > Algorithm        : topsort
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

vector<int> G[maxn];
int degree[maxn];
queue<int> q;

int n, m, top[maxn], cnt, dp[maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int x = read(), y = read();
        G[x].push_back(y);
        degree[y]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 0) {
            q.push(i);
            top[++cnt] = i;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < G[u].size(); ++i) {
            int& v = G[u][i];
            degree[v]--;
            if (degree[v] == 0) {
                q.push(v);
                top[++cnt] = v;
            }
        }
    }
    for (int i = 1; i <= n; ++i) dp[i] = 1;
    for (int _u = 1; _u <= n; ++_u) {
        int u = top[_u];
        for (int i = 0; i < G[u].size(); ++i) {
            int& v = G[u][i];
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", dp[i]);
    }
    return 0;
}