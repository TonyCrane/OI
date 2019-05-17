/*************************************************************
 *  > File Name        : P3389.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/17 23:41:20
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const double eps = 1e-8;

typedef double Matrix[maxn][maxn];

void Gauss(Matrix A, int n) {
    int r;
    for (int i = 0; i < n; ++i) {
        r = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        }
        if (fabs(A[r][i]) < eps) {
            printf("No Solution\n");
            exit(0);
        }
        if (r != i) {
            for (int j = 0; j <= n; ++j) {
                swap(A[r][j], A[i][j]);
            }
        }
        for (int k = i + 1; k < n; ++k) {
            double f = A[k][i] / A[i][i];
            for (int j = i; j <= n; ++j) {
                A[k][j] -= f * A[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            A[i][n] -= A[j][n] * A[i][j];
        }
        A[i][n] /= A[i][i];
    }
}

int main() {
    int n; scanf("%d", &n);
    Matrix A;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            scanf("%lf", &A[i][j]);
        }
    }
    Gauss(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%.2f\n", A[i][n]);
    }
    return 0;
}