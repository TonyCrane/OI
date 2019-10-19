/*************************************************************
 *  > File Name        : maths.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/18 16:46:35
 *  > Algorithm        : math 40 Points
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

const LL maxn = 10000010;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool vis[maxn];
LL prime[maxn];
void getprime(LL n) {
    LL m = (LL)sqrt(n + 0.5), num = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
    for (LL i = 2; i <= m; ++i) if (!vis[i]) {
        prime[++num] = i;
        for (LL j = i * i; j <= n; j += i) vis[j] = 1;
    }
}

int main() {
    LL T = read();
    getprime(10000000);
    while (T--) {
        LL n = read(), ans = 0;
        if (!vis[n]) {
            printf("%lld\n", n * (n - 1) + 1);
            continue;
        }
        for (LL i = 1; i <= n; ++i) {
            ans += n / gcd(i, n);
        }
        printf("%lld\n", ans);
    }
    return 0;
}