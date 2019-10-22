/*************************************************************
 *  > File Name        : P3243.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/22 21:19:08
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

vector<int> G[maxn]; int n, m;
int degree[maxn], top[maxn], cnt;

int main() {
    int T = read();
    while (T--) {
        for (int i = 0; i <= n; ++i) G[i].clear();
        memset(degree, 0, sizeof(degree));
        memset(top, 0, sizeof(top)); cnt = 0;
        queue<int> q;
        n = read(), m = read();
        for (int i = 1; i <= m; ++i) {
            int u = read(), v = read();
            G[v].push_back(u);
            degree[u]++;
        }
        for (int i = 1; i <= n; ++i) {
            if (!degree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            top[++cnt] = u;
            for (int i = 0; i < G[u].size(); ++i) {
                int& v = G[u][i];
                degree[v]--;
                if (!degree[v]) {
                    q.push(v);
                }
            }
        }
        if (cnt < n) {
            printf("Impossible!\n");
        } else {
            for (int i = n; i >= 1; --i) {
                printf("%d ", top[i]);
            }
            puts("");
        }
    }
    return 0;
}