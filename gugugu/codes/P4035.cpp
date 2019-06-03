/*************************************************************
 *  > File Name        : P4035.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/03 13:08:09
 *  > Algorithm        : [Math]Gauss
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 30;

int n;
double a[maxn][maxn], b[maxn][maxn];

void Gauss() {
    int r;
    for (int i = 0; i < n; ++i) {
        r = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(a[j][i]) > fabs(a[r][i])) r = j;
        }
        if (r != i) {
            for (int j = 0; j <= n; ++j) {
                swap(a[r][j], a[i][j]);
            }
        }
        for (int k = i + 1; k < n; ++k) {
            double f = a[k][i] / a[i][i];
            for (int j = i; j <= n; ++j) {
                a[k][j] -= f * a[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            a[i][n] -= a[j][n] * a[i][j];
        }
        a[i][n] /= a[i][i];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &b[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 2 * (b[i + 1][j] - b[i][j]);
            a[i][n + 1] += (b[i + 1][j] * b[i + 1][j] - b[i][j] * b[i][j]);
        }
    }
    Gauss();
    for (int i = 0; i < n; i++) {
        printf("%.3f ", a[i][n + 1]);
    }
    return 0;
}