/*************************************************************
 *  > File Name        : P4526.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/02 12:36:54
 *  > Algorithm        : [Math]SimpsonIntegral
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

double a;

inline double f(double x) {
    return pow(x, (a / x) - x);
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
    scanf("%lf", &a);
    if (a < 0) return printf("orz\n"), 0;
    printf("%.5lf\n", integral(0, 20, 1e-10));
    return 0;
}