/*************************************************************
 *  > File Name        : P1919.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/08 21:19:12
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

const int maxn = 2100000;
const double PI = acos(-1.0);

int deg, rev[maxn], lim = 1, ans[maxn];

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

char num1[maxn], num2[maxn];

int main() {
    scanf("%s%s", num1, num2); 
    int n = strlen(num1) - 1, m = strlen(num2) - 1, cnt1 = 0, cnt2 = 0;
    for (int i = n; i >= 0; --i) F[i].r = num1[cnt1++] - '0';
    for (int i = m; i >= 0; --i) G[i].r = num2[cnt2++] - '0';
    while (lim <= n + m) lim <<= 1, deg++;
    for (int i = 0; i < lim; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (deg - 1));
    FFT(F, 1);
    FFT(G, 1);
    for (int i = 0; i <= lim; ++i) F[i] = F[i] * G[i];
    FFT(F, -1);
    for (int i = 0; i <= lim; ++i) {
        ans[i] += (int)(F[i].r / lim + 0.5);
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == lim) lim++;
        }
    }
    while (!ans[lim] && lim >= 1) lim--;
    while (lim >= 0) printf("%d", ans[lim--]);
    return 0;
}