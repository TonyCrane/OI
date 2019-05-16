/*************************************************************
 *  > File Name        : P4720.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 13:08:45
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1000010;

LL a[maxn], c[maxn], n, m, p, cnt;

inline void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

inline LL inv(LL a, LL n) {
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return (x + n) % n;
}

inline LL pow_mod(LL a, LL p, LL n) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * a % n;
        a = a * a % n;
        p >>= 1;
    }
    return res;
}

inline LL crt(){
    LL M = 1, ans = 0;
    for (int i = 0; i < cnt; ++i) M *= c[i];
    for (int i = 0; i < cnt; ++i) {
        ans = (ans + a[i] * (M / c[i]) % M * inv(M / c[i], c[i]) % M) % M;
    }
    return ans;
}

LL fac(LL n, LL p, LL pk) {
    if (!n) return 1; LL ans = 1;
    for (int i = 1; i < pk; ++i)
        if (i % p) ans = ans * i % pk;
    ans = pow_mod(ans, n / pk, pk);
    for (int i = 1; i <= n % pk; ++i)
        if (i % p) ans = ans * i % pk;
    return ans * fac(n / p, p, pk) % pk;
}

LL C(LL n, LL m, LL p, LL pk) {
    if (n < m) return 0;
    LL N = fac(n, p, pk), M = fac(m, p, pk), Z = fac(n - m, p, pk), cnt = 0;
    for (LL i = n; i; i /= p) cnt += i / p;
    for (LL i = m; i; i /= p) cnt -= i / p;
    for (LL i = n - m; i; i /= p) cnt -= i / p;
    return N * inv(M, pk) % pk * inv(Z, pk) % pk * pow_mod(p, cnt, pk) % pk;
}

LL exLucas(LL n, LL m, LL p) {
    LL tmp = sqrt(p);
    for (int i = 2; p > 1 && i <= tmp; ++i) {
        LL tmp = 1;
        while (p % i == 0) p /= i, tmp *= i;
        if (tmp > 1) c[cnt] = tmp, a[cnt++] = C(n, m, i, tmp);
    }
    if (p > 1) c[cnt] = p, a[cnt++] = C(n, m, p, p);
    return crt();
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &p);
    printf("%lld\n", exLucas(n, m, p));
    return 0;
}