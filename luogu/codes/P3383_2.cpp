/*************************************************************
 *  > File Name        : P3383_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/09 16:34:20
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 10000010;

bool vis[maxn];
int prime[maxn];

void getprime(int n) {
    int m = (int)sqrt(n + 0.5), num = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
    for (int i = 2; i <= m; ++i) if (!vis[i]) {
        prime[++num] = i;
        for (int j = i * i; j <= n; j += i) vis[j] = 1;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getprime(n);
    for (int i = 1; i <= m; ++i) {
        int que;
        scanf("%d", &que);
        printf(vis[que]? "No\n" : "Yes\n");
    }
    return 0;
}