/*************************************************************
 *  > File Name        : P4525.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/02 12:29:38
 *  > Algorithm        : [Math]SimpsonIntegral
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

double a, b, c, d, l, r;

inline double f(double x) {
    return (c * x + d) / (a * x + b);
}

inline double simpson(double l, double r) {
    double mid = (l + r) / 2;
    return (f(l) + 4 * f(mid) + f(r)) * (r - l) / 6;
}

double asr(double l, double r, double eps, double ans) {
    double mid = (l + r) / 2;
    double L = simpson(l, mid), R = simpson(mid, r);
    if (fabs(L + R - ans) <= 15 * eps) return L + R + (L + R - ans) / 15;
    return asr(l, mid, eps / 2, L) + asr(mid, r, eps / 2, R);
}

double integral(double l, double r, double eps) {
    return asr(l, r, eps, simpson(l, r));
}

int main() {
    scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &l, &r);
    printf("%.6lf\n", integral(l, r, 1e-6));
    return 0;
}