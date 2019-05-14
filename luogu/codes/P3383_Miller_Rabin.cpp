/*************************************************************
 *  > File Name        : P3383_Miller_Rabin.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/14 12:47:17
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL Random(LL n) { return (LL)((double)rand() / RAND_MAX * n + 0.5); }

LL pow_mod(LL a, LL p, LL n) {
    a %= n; LL ans = 1;
    for (; p; p >>= 1, a *= a, a %= n) if(p & 1) ans = ans * a % n;
    return ans;
}

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
    for (int i = 1; i <= 30; ++i) {
        LL a = Random(n - 2) + 1;
        if (Witness(a, n)) return false;
    }
    return true;
}

int main() {
    LL n, m, x;
    scanf("%lld %lld", &n, &m);
    while (scanf("%lld", &x) == 1) {
        if (Miller_Rabin(x)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}