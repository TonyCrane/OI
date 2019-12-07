/*************************************************************
 *  > File Name        : P3803.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/07 17:30:18
 *  > Algorithm        : FFT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2000010;
const double PI = acos(-1.0);

struct Complex {
    double r, i;
    Complex() {}
    Complex(double real, double imag): r(real), i(imag) {}
}F[maxn], G[maxn];
Complex operator + (Complex a, Complex b) { return Complex(a.r + b.r, a.i + b.i); }
Complex operator - (Complex a, Complex b) { return Complex(a.r - b.r, a.i - b.i); }
Complex operator * (Complex a, Complex b) { return Complex(a.r * b.r - a.i * b.i, a.r * b.i + a.i * b.r); }

void FFT(int lim, Complex* A, int opt) {
    if (lim == 1) return;
    Complex a0[lim >> 1], a1[lim >> 1];
    for (int i = 0; i <= lim; i += 2) a0[i >> 1] = A[i], a1[i >> 1] = A[i + 1];
    FFT(lim >> 1, a0, opt);
    FFT(lim >> 1, a1, opt);
    Complex wn = Complex(cos(2.0 * PI / lim), opt * sin(2.0 * PI / lim));
    Complex w  = Complex(1, 0);
    for (int k = 0; k < (lim >> 1); ++k) {
        A[k] = a0[k] + w * a1[k];
        A[k + (lim >> 1)] = a0[k] - w * a1[k];
        w = w * wn;
    }
}

int main() {
    int n = read(), m = read();
    for (int i = 0; i <= n; ++i) F[i].r = read();
    for (int i = 0; i <= n; ++i) G[i].r = read();
    int lim = 1;
    while (lim <= n + m) lim <<= 1;
    FFT(lim, F, 1);
    FFT(lim, G, 1);
    for (int i = 0; i <= lim; ++i) F[i] = F[i] * G[i];
    FFT(lim, F, -1);
    for (int i = 0; i <= n + m; ++i) {
        printf("%d ", (int)(F[i].r / lim + 0.5));
    }
    return 0;
}