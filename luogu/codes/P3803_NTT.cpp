/*************************************************************
 *  > File Name        : P3803_NTT.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/11 12:30:08
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2100000;
const int mod  = 998244353;
const int g = 3, invg = 332748118;

int rev[maxn], lim = 1, cnt;
LL F[maxn], G[maxn];

LL pow_mod(LL a, LL p, LL n){
    int res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
}

void NTT(LL* A, int opt) {
    for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int s = 1; s <= log2(lim); ++s) {
        int m = 1 << s; LL wn;
        if (opt == 1) wn = pow_mod(g, (mod - 1) / m, mod);
        else wn = pow_mod(invg, (mod - 1) / m, mod);
        for (int k = 0; k < lim; k += m) {
            LL w = 1;
            for (int j = 0; j < m / 2; ++j) {
                LL t = w * (LL)A[k + j + m / 2] % mod;
                LL u = A[k + j];
                A[k + j] = (u + t) % mod;
                A[k + j + m / 2] = (u - t + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if (opt == -1) {
        LL inv = pow_mod(lim, mod - 2, mod);
        for (int i = 0; i < lim; ++i) A[i] = A[i] * inv % mod;
    }
}

int main() {
    int n = read(), m = read();
    for (int i = 0; i <= n; ++i) F[i] = (read() % mod + mod) % mod;
    for (int i = 0; i <= m; ++i) G[i] = (read() % mod + mod) % mod;
    while (lim <= n + m) lim <<= 1, cnt++;
    for (int i = 0; i < lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
    NTT(F, 1);
    NTT(G, 1);
    for (int i = 0; i <= lim; ++i) F[i] = F[i] * G[i] % mod;
    NTT(F, -1);
    for (int i = 0; i <= n + m; ++i) {
        printf("%lld ", F[i]);
    }
    return 0;
}