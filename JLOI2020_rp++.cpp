/*************************************************************
 *  > Description      : 复赛相关模板
 *  > File Name        : JLOI2020_rp++.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/12/12 12:20:39
 *  > Copyright (C) 2019 Tony_Wong
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

/*-------------------------------- 数论 --------------------------------*/

/* FFT */

const int maxn = 2100010;
const double PI = acos(-1.0);

int cnt, rev[maxn], lim = 1;

struct Complex {
    double r, i;
    Complex() { r = 0, i = 0; }
    Complex(double real, double imag): r(real), i(imag) {}
}F[maxn], G[maxn];
Complex operator + (Complex a, Complex b) { return Complex(a.r + b.r, a.i + b.i); }
Complex operator - (Complex a, Complex b) { return Complex(a.r - b.r, a.i - b.i); }
Complex operator * (Complex a, Complex b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }

void FFT(Complex* A, int opt) {
    for (int i = 0; i < lim; ++i) if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int s = 1; s <= log2(lim); ++s) {
        int m = 1 << s;
        Complex wn = Complex(cos(2 * PI / m), opt * sin(2 * PI / m));
        for (int k = 0; k < lim; k += m) {
            Complex w = Complex(1, 0);
            for (int j = 0; j < m / 2; ++j) {
                Complex t = w * A[k + j + m / 2];
                Complex u = A[k + j];
                A[k + j] = u + t;
                A[k + j + m / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if (opt == -1) for (int i = 0; i < lim; ++i) F[i].r /= lim;
}


/* NTT */
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



/*-------------------------------- 数据结构 --------------------------------*/

/* 线性基 */
int n;
LL a[maxn], p[64];
bool flag = true;  // 全能插入,则为true,有插入失败的,则为false

bool insert(LL x) {
    for (int i = 61; i >= 0; --i) {
        if (x & (1LL << i)) {
            if (p[i]) x ^= p[i];
            else {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

LL queryMax() {
    LL ans = 0;
    for (int i = 61; i >= 0; --i) {
        if ((ans ^ p[i]) > ans) {
            ans ^= p[i];
        }
    }
    return ans;
}

LL queryMin() {
    if (!flag) return 0LL;
    for (int i = 0; i <= 61; ++i) {
        if (p[i]) return p[i];
    }
}

LL queryKth(LL k) { // 第k小
    if (k == 1LL && !flag) return 0;
    if (!flag) k--;
    for (int i = 1; i <= 61; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (p[i] & (1LL << (j - 1))) p[i] ^= p[j - 1];
        }
    }
    LL ans = 0;
    for (int i = 0; i <= 61; ++i) {
        if (d[i] != 0) {
            if (k & 1) ans ^= p[i];
            k /= 2;
        }
    }
    return ans;
}