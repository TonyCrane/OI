/*************************************************************
 *  > File Name        : c1089_0.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 13:46:40
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

const int maxn = 100010;

int n, m, ans[maxn];
bool vis[maxn];

struct Require {
    int l, r;
    bool operator < (const Require& a) const {
        if (l == a.l) return r < a.r;
        return l < a.l;
    }
}r[maxn];

priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int T = read();
    while (T--) {
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        n = read(); m = read();
        for (int i = 1; i <= m; ++i) {
            r[i].l = read(); r[i].r = read();
        }
        sort(r + 1, r + 1 + m);
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        int nowreq = 1, now = 1;
        for (int i = 1; i <= n; ++i) {
            while (r[nowreq].l == i && nowreq <= m) {
                if (i > now) now = i;
                for (; now <= r[nowreq].r; ++now) {
                    ans[now] = q.top();
                    q.pop();
                    vis[ans[now]] = 1;
                }
                nowreq++;
            }
            if (!ans[i]) ans[i] = 1;
            else if (vis[ans[i]]) {
                vis[ans[i]] = false;
                q.push(ans[i]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ans[i]);
        }
        puts("");
        while (!q.empty()) q.pop();
    }
    return 0;
}