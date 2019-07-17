/*************************************************************
 *  > File Name        : P1441.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/21 15:27:10
 *  > Algorithm        : [Dfs+DP]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 22;
const int maxm = 2010;

int n, m, ans, cnt, tmp;
int a[maxn];
bool dp[maxm], vis[maxn];

void DP() {
    memset(dp, 0, sizeof(dp)); dp[0] = true;
    cnt = 0; tmp = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        for (int j = cnt; j >= 0; --j) {
            if (dp[j] && !dp[j + a[i]]) {
                dp[j + a[i]] = true;
                tmp++;
            }
        }
        cnt += a[i];
    }
    ans = max(ans, tmp);
}

void dfs(int now, int cur) {
    if (now > m) return;
    if (cur == n) {
        if (now == m) {
            DP();
        }
        return;
    }
    dfs(now, cur + 1);
    vis[cur] = true;
    dfs(now + 1, cur + 1);
    vis[cur] = false;
}

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}