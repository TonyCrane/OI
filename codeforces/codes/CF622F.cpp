/*************************************************************
 *  > File Name        : CF622F.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/06 12:48:29
 *  > Algorithm        : Lagrange
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0; long long f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const long long maxn = 2000010;
const long long mod  = 1e9 + 7;

long long pow_mod(long long a, long long p, long long n){
    long long res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
}

long long inv(long long x) {
    return pow_mod(x % mod, mod - 2, mod);
}

long long n, k, y, pre[maxn], suf[maxn], fac[maxn];
long long ans = 0;

int main() {
    n = read(); k = read();
    fac[0] = pre[0] = suf[k + 3] = 1;
    for (int i = 1; i <= k + 2; ++i) fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= k + 2; ++i) pre[i] = pre[i - 1] * (n - i) % mod;
    for (int i = k + 2; i >= 1; --i) suf[i] = suf[i + 1] * (n - i) % mod;
    for (int i = 1; i <= k + 2; ++i) {
        y = (y + pow_mod(i, k, mod)) % mod;
        long long up = 1LL * pre[i - 1] * suf[i + 1] % mod;
        long long down = ((k - i) & 1 ? -1LL : 1LL) * fac[i - 1] * fac[k + 2 - i] % mod;
        ans = (ans + 1LL * y * up % mod * inv(down) % mod) % mod; 
    }
    printf("%lld\n", (ans + mod) % mod);
    return 0;
}