/*************************************************************
 *  > File Name        : c1077_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/18 13:04:12
 *  > Algorithm        : 二分图 80 Points
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

vector<int> G[maxn];
void add(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}
stack<pair<int, int> > s;

int n, m, color[maxn], lastu;
bool vis[maxn];

bool dfs(int u, int col) {
    color[u] = col;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (color[v] == col) return false;
        if (color[v] == 0 && !dfs(v, -col)) return false;
    }
    return true;
}

void judge() {
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; ++i) {
        if (vis[i] && color[i] == 0) {
            if (!dfs(i, 1)) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int main() {
    n = read(); m = read();
    while (m--) {
        int opt = read();
        if (opt == 1) {
            int x = read(), y = read();
            add(x, y); s.push(pair<int, int>(x, y));
            vis[x] = true; vis[y] = true;
            judge();
        } else {
            pair<int, int> p = s.top(); s.pop();
            vis[p.first] = false; vis[p.second] = false;
            G[p.first].pop_back();
            G[p.second].pop_back();
            judge();
        }
    }
    return 0;
}