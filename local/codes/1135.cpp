/*************************************************************
 *  > File Name        : 1135.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 17:30:14
 *  > Algorithm        : Math+dfs
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

LL pow_mod(LL a, LL p){
    int res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        p >>= 1;
    }
    return res;
}

LL n, k, ans;
int go[10];

bool check() {
    bool vis[10];
    memset(vis, 0, sizeof(vis));
    int now = 1;
    while (!vis[now]) {
        vis[now] = true;
        now = go[now];
    }
    if (now != 1) return false;
    for (int i = 1; i <= k; ++i) {
        if (!vis[i]) {
            bool vis2[10];
            memset(vis2, 0, sizeof(vis2));
            int now = i;
            while (!vis2[now] && !vis[now]) {
                vis2[now] = true;
                now = go[now];
            }
            if (!vis[now]) return false;
        }
    }
    return true;
}

void dfs(int now) {
    if (now == k + 1) {
        if (check()) ans++;
        return;
    }
    for (int i = 1; i <= k; ++i) {
        go[now] = i;
        dfs(now + 1);
    }
}

int main() {
    scanf("%lld %lld", &n, &k);
    dfs(1);
    ans = ans * pow_mod(n - k, n - k) % mod;
    printf("%lld\n", ans);
    return 0;
}