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

int deg, rev[maxn], lim = 1;

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
}

int main() {
    int n = read(), m = read();
    for (int i = 0; i <= n; ++i) F[i].r = read();
    for (int i = 0; i <= m; ++i) G[i].r = read();
    while (lim <= n + m) lim <<= 1, deg++;
    for (int i = 0; i < lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (deg - 1));
    FFT(F, 1);
    FFT(G, 1);
    for (int i = 0; i <= lim; ++i) F[i] = F[i] * G[i];
    FFT(F, -1);
    for (int i = 0; i <= n + m; ++i) {
        printf("%d ", (int)(F[i].r / lim + 0.5));
    }
    return 0;
}