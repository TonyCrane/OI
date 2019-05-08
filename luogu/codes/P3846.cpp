/*************************************************************
 *  > File Name        : P3846.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/08 15:46:21
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

LL mul_mod(LL a, LL b, int n) {
    a %= n; b %= n; return a * b % n;
}

LL pow_mod(LL a, LL p, LL n) {
    if (p == 0 && n == 1) return 0;
    if (p == 0) return 1;
    LL ans = pow_mod(a, p / 2, n); ans = ans * ans % n;
    if (p % 2 == 1) ans = ans * a % n;
    return ans;
}

LL inv(LL a, LL n) {
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

int log_mod(int a, int b, int n) {
    int m, v, e = 1, i;
    m = (int)sqrt(n + 0.5);
    v = inv(pow_mod(a, m, n), n);
    map<int, int> x;
    x[1] = 0;
    for (i = 1; i < m; ++i) {
        e = mul_mod(e, a, n);
        if (!x.count(e)) x[e] = i;
    }
    for (i = 0; i < m; ++i) {
        if (x.count(b)) return i * m + x[b];
        b = mul_mod(b, v, n);
    }
    return -1;
}

int main() {
    int p, b, n;
    scanf("%d %d %d", &p, &b, &n);
    int ans = log_mod(b, n, p);
    if (ans == -1) {
        printf("no solution\n");
    } else {
        printf("%d\n", ans);
    }
    return 0;
}