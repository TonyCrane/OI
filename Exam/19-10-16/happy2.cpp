/*************************************************************
 *  > File Name        : happy2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/16 12:23:42
 *  > Algorithm        : math 100 Points
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

const LL maxn = 100010;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool vis[maxn];
LL n, m, k;

int main() {
    int T = read();
    while (T--) {
        memset(vis, 0, sizeof(vis));
        n = read(); m = read(); k = read();
        LL mod = gcd(gcd(n, m), k);
        LL b = read(), u;
        for (LL i = 0; i < b; ++i) {
            u = read();
            vis[u % mod] = true;
        }
        LL g = read();
        for (LL i = 0; i < g; ++i) {
            u = read();
            vis[u % mod] = true;
        }
        LL t = read();
        for (LL i = 0; i < t; ++i) {
            u = read();
            vis[u % mod] = true;
        }
        if (b == 0 && g == 0 && t == 0) {
            printf("No\n");
            continue;
        }
        bool ok = true;
        for (LL i = 0; i < mod; ++i) {
            if (!vis[i]) {
                ok = false;
                break;
            }
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}