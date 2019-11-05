/*************************************************************
 *  > File Name        : c1084_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/05 16:12:18
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

const int maxn = 50010;

int n, k, val[maxn], ans1, ans2, cnt[maxn];
bool vis[maxn];
priority_queue<int, vector<int>, greater<int> > q[maxn];

int main() {
    int T = read();
    while (T--) {
        n = read(); k = read(); ans1 = 0; ans2 = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) vis[i] = (bool)read();
        for (int i = 1; i <= n; ++i) val[i] = read(), ans1 += val[i];
        ans2 = ans1;
        for (int i = 1; i <= k; ++i) {
            for (int j = i; j <= n; j += k) {
                q[i].push(val[j]);
                if (!vis[j]) cnt[i] ^= 1;
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (cnt[i]) ans1 -= q[i].top();
            while (!q[i].empty()) q[i].pop();
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= k; ++i) vis[i] ^= 1;
        for (int i = 1; i <= k; ++i) {
            for (int j = i; j <= n; j += k) {
                q[i].push(val[j]);
                if (!vis[j]) cnt[i] ^= 1;
            }
        }
        for (int i = 1; i <= k; ++i) {
            if (cnt[i]) ans2 -= q[i].top();
            while (!q[i].empty()) q[i].pop();
        }
        printf("%d\n", max(ans1, ans2));
    }
    return 0;
}