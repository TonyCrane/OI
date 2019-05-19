/*************************************************************
 *  > File Name        : P4593.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/19 15:25:54
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int p = 1e9 + 7;
const int maxn = 60;

int ans, num, pro, a[maxn], f[maxn], fac[maxn] = {1};

inline int pow_mod(int a, int b){
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int Lagrange(int n, int k) {
    pro = 1; num = 0;
    if (n <= k) return f[n];
    for (int i = 1; i <= k; ++i) {
        pro = pro * (n - i) % p;
    }
    for (int i = 1; i <= k; ++i) {
        int inv1 = pow_mod(n - i, p - 2);
        int inv2 = pow_mod((fac[i - 1] % p * fac[k - i]) % p, p - 2);
        int sign = (k - i) & 1 ? -1 : 1;
        num = (num + sign * inv1 * inv2 % p * f[i] % p * pro % p) % p;
    }
    return (num + p) % p;
}

signed main() {
    for (int i = 1; i < maxn; ++i) {
        fac[i] = fac[i - 1] * i % p;
    }
    int T = read();
    while (T--) {
        int n = read(), m = read();
        for (int i = 1; i <= m + 3; ++i) {
            f[i] = (f[i - 1] + pow_mod(i, m + 1)) % p;
        }
        for (int i = 1; i <= m; ++i) {
            a[i] = read();
        }
        sort(a + 1, a + m + 1);
        ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans = (ans + Lagrange(n - a[i], m + 3)) % p;
            for (int j = i + 1; j <= m; ++j) {
                ans = (ans + p - pow_mod(a[j] - a[i], m + 1)) % p;
            }
        }
        printf("%d\n", (ans + p) % p);
    }
    return 0;
}