/*************************************************************
 *  > File Name        : P4718.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/14 16:09:15
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL maxn, vis[510];
int cnt;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL mul_mod(LL a, LL b, LL n){
    LL res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}

LL pow_mod(LL a, LL p, LL n) {
    a %= n; LL ans = 1;
    for (; p; p >>= 1, a *= a, a %= n) if(p & 1) ans = ans * a % n;
    return ans;
}

LL Random(LL n) { return (LL)((double)rand() / RAND_MAX * n + 0.5); }

bool Witness(LL a, LL n) {
    LL m = n - 1; int j = 0;
    while (!(m & 1)) { j++; m >>= 1; }
    LL x = pow_mod(a, m, n);
    if (x == 1 || x == n - 1) return false;
    while (j--) { x = x * x % n; if (x == n - 1) return false; }
    return true;
}

bool Miller_Rabin(LL n) {
    if (n < 2) return false; if (n == 2) return true;
    if (!(n & 1)) return false;
    for (int i = 1; i <= 10; ++i) {
        LL a = Random(n - 2) + 1;
        if (Witness(a, n)) return false;
    }
    return true;
}

LL Pollard_Rho(LL n, int c) {
    LL x, y, d, i = 1, k = 2;
    x = Random(n - 1) + 1; y = x;
    while (true) {
        i++;
        x = (mul_mod(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if (1 < d && d < n) return d;
        if (y == x) return n;
        if (i == k) { y = x; k <<= 1; }
    }
}

void find(LL n, int k) {
    if (n == 1) return;
    if (Miller_Rabin(n)) {
        vis[++cnt] = n;
        if (n > maxn) maxn = n;
        return;
    }
    LL p = n;
    while (p >= n) p = Pollard_Rho(p, k--);
    find(p, k); find(n / p, k);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        LL n;
        scanf("%lld", &n);
        maxn = 0;
        if (Miller_Rabin(n)) printf("Prime\n");
        else { find(n, 201); printf("%lld\n", maxn); }
    }
    return 0;
}