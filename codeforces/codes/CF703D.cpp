/*************************************************************
 *  > File Name        : CF703D.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/17 15:01:14
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

const int maxn = 1000010;

int n, m, now, sum;
int t[maxn], a[maxn], b[maxn], ans[maxn], nxt[maxn];
map<int, int> vis, pre;
vector<pair<int, int> > Q[maxn];

void add(int x, int k) {
    for (; x <= n; x += x & -x) t[x] ^= k;
}

int ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res ^= t[x];
    return res;
}

int main() {
    n = read();
    now = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        vis[a[i]]++;
        nxt[pre[a[i]]] = i;
        pre[a[i]] = i;
        if (vis[a[i]] >= 2) {
            now ^= a[i];
        }
        b[i] = now;
    }
    m = read();
    for (int i = 1; i <= m; ++i) {
        int l = read(), r = read();
        Q[l].push_back(pair<int, int>(r, i));
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < Q[i].size(); ++j) {
            ans[Q[i][j].second] = ask(Q[i][j].first) ^ b[Q[i][j].first];
        }
        if (nxt[i]) {
            sum ^= a[i];
            add(nxt[i], a[i]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}