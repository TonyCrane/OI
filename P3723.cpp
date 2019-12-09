/*************************************************************
 *  > File Name        : P3723.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/09 12:24:33
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

const int maxn = 2100010;
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

int n, m, ans = 0x3f3f3f3f;
int x[maxn], y[maxn], x2, y2, sx, sy;

int main() {
    n = read(), m = read();
    for (int i = 0; i < n; ++i) {
        x[i] = read();
        x2 += x[i] * x[i];
        sx += x[i];
        F[i + n].r = F[i].r = x[i];
    }
    for (int i = 0; i < n; ++i) {
        y[i] = read();
        y2 += y[i] * y[i];
        sy += y[i];
        G[n - i].r = y[i];
    }
    while (lim <= 3 * n) lim <<= 1, deg++;
    for (int i = 0; i < lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (deg - 1));
    FFT(F, 1); FFT(G, 1);
    for (int i = 0; i <= lim; ++i) F[i] = F[i] * G[i];
    FFT(F, -1);
    for (int i = 0; i <= 3 * n; ++i) F[i].r = (int)(F[i].r / lim + 0.5);
    for (int i = 0; i < m; ++i) {
        for (int delta = -m; delta <= m; ++delta) {
            ans = min(ans, x2 + y2 + 2 * delta * )
        }
    }
}