/*************************************************************
 *  > File Name        : CF1251E1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 17:02:51
 *  > Algorithm        : greedy
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 200010;

LL n, ans;
vector<LL> G[maxn];
priority_queue<LL, vector<LL>, greater<LL> > q;

int main() {
    LL T = read();
    while (T--) {
        for (LL i = 0; i <= n; ++i) G[i].clear();
        while (!q.empty()) q.pop();
        n = read(); ans = 0;
        for (LL i = 1; i <= n; ++i) {
            LL x = read(), y = read();
            G[x].push_back(y);
        }
        for (LL i = n - 1; i >= 0; --i) {
            for (LL j = 0; j < G[i].size(); ++j) {
                q.push(G[i][j]);
            }
            while (q.size() > n - i) {
                ans += q.top(); q.pop();
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}