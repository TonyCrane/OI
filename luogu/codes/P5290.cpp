/*************************************************************
 *  > File Name        : P5290.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/21 12:42:35
 *  > Algorithm        : 
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

const int maxn = 200010;

int n, m[maxn], f[maxn];
LL ans = 0;
vector<int> G[maxn];
priority_queue<int> q[maxn];

void unionn(int v, int u) {
    if (q[v].size() > q[u].size()) swap(q[v], q[u]);
    stack<int> s;
    while (!q[v].empty()) {
        s.push(max(q[u].top(), q[v].top()));
        q[v].pop(); q[u].pop();
    }
    while (!s.empty()) {
        q[u].push(s.top());
        s.pop();
    }
}

void dfs(int u) {
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        dfs(v);
        unionn(v, u);
    }
    q[u].push(m[u]);
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        m[i] = read();
    }
    for (int i = 2; i <= n; ++i) {
        f[i] = read();
        G[f[i]].push_back(i);
    }
    dfs(1);
    while (!q[1].empty()) {
        ans += q[1].top();
        q[1].pop();
    }
    printf("%lld\n", ans);
    return 0;
}