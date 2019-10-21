/*************************************************************
 *  > File Name        : c1077_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/18 15:14:23
 *  > Algorithm        : math 100 PoLLs
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

LL f[maxn], s[maxn];

int main() {
    LL T = read();
    getprime(10000000);
    for (LL i = 1; i < maxn; ++i) f[i] = 1LL;
    for (LL i = 2; i < maxn - 10; ++i) {
        if (!vis[i]) {
            s[i] = i; f[i] = (LL)(i - 1) * i + 1;
            for (LL j = i, k = i * j; j < maxn && k < maxn; j = k, k = i * j) {
                f[k] = (f[j] * i * i) - i + 1;
                s[k] = i;
            }
        }
        if (s[i]) {
            for (LL j = 2; i * j < maxn; ++j) {
                if (j % s[i]) {
                    f[i * j] = f[i] * f[j];
                }
            }
        }
    }
    while (T--) {
        LL n = read();
        printf("%lld\n", f[n]);
    }
    return 0;
}