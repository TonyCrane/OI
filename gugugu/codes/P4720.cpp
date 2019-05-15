/*************************************************************
 *  > File Name        : P4720.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 13:08:45
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

void exgcd(int a, int b, int& d, int& x, int& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int inv(int a, int n) {
    int d, x, y;
    exgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

int pow_mod(int a, int p, int n) {
    a %= n; int ans = 1;
    for (; p; p >>= 1, a *= a, a %= n)
        if(p & 1) ans = ans * a % n;
    return ans;
}

int crt(int x, int p, int mod){
    return inv(p / mod, mod) * (p / mod) * x;
}

int fac(int x, int a, int p) {
    if (x == 0) return 1;
    int ans = 1;
    for (int i = 1; i <= p; ++i) {
        if (i % a) {
            ans *= i;
            ans %= p;
        }
    }
    ans = pow_mod(ans, x / p, p);
    for (int i = 1; i <= x % p; ++i) {
        if (i % a) {
            ans *= i;
            ans %= p;
        }
    }
    return ans * fac(x / a, a, p) % p;
}

int C(int n, int m, int a, int b) {
    int N = fac(n, a, b), M = fac(m, a, b), Z = fac(n - m, a, b), sum = 0;
    for (int i = n; i; i = i / a) sum += i / a;
    for (int i = m; i; i = i / a) sum -= i / a;
    for (int i = n - m; i; i = i / a) sum -= i / a;
    return N * pow_mod(a, sum, b) % b * inv(M, b) % b * inv(Z, b) % b;
}

void exLucas(int n, int m, int p) {
    int t = p, ans = 0;
    for (int i = 2; i * i <= p; ++i) {
        int k = 1;
        while (t % i == 0) {
            k *= i;
            t /= i;
        }
        ans += crt(C(n, m, i, k), p, k);
        ans %= p;
    }
    if (t > 1) {
        ans += crt(C(n, m, t, t), p, t);
        ans %= p;
    }
    printf("%d\n", ans % p);
}

int main() {
    int n = read(), m = read(), p = read();
    exLucas(n, m, p);
    return 0;
}