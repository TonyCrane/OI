/*************************************************************
 *  > File Name        : P1725.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/15 15:38:51
 *  > Algorithm        : 单调队列DP
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

int ans, n, l, r, a[maxn], dp[maxn];
deque<int> q;

int main() {
    n = read(); l = read(); r = read();
    for (int i = 0; i <= n; ++i) {
        a[i] = read();
    }
    memset(dp, 0xcf, sizeof(dp));
    ans = 0xcfcfcfcf; dp[0] = 0; int p = 0;
    for (int i = l; i <= n; ++i) {
        while (!q.empty() && dp[q.back()] <= dp[p]) {
            q.pop_back();
        }
        q.push_back(p);
        while (q.front() + r < i) {
            q.pop_front();
        }
        dp[i] = dp[q.front()] + a[i];
        p++;
    }
    for (int i = n - r + 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}