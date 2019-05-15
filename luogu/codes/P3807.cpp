/*************************************************************
 *  > File Name        : P3807.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 12:48:29
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 100010;

LL c[maxn];
int p;

LL pow_mod(LL a, LL p, LL n) {
    a %= n; LL ans = 1;
    for (; p; p >>= 1, a *= a, a %= n) 
        if(p & 1) ans = ans * a % n;
    return ans;
}

LL C(LL a, LL b) {
    if (a < b) return 0;
    return ((c[a] * pow_mod(c[b], p - 2, p)) % p * pow_mod(c[a - b], p - 2, p) % p);
}

LL Lucas(LL n, LL m) {
    if (m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d %d", &n, &m, &p);
        c[0] = 1;
        for (int i = 1; i <= p; ++i) c[i] = (c[i - 1] * i) % p;
        printf("%lld\n", Lucas(n + m, n));
    }
    return 0;
}