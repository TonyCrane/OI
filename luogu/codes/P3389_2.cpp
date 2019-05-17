/*************************************************************
 *  > File Name        : P3389_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/17 23:58:26
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const double eps = 1e-8;

typedef double Matrix[maxn][maxn];

void Gauss_jordan(Matrix A, int n) {
    int r;
    for (int i = 0; i < n; i++) {
        r = i;
        for (int j = i + 1; j < n; j++)
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        if (fabs(A[r][i]) < eps) {
            printf("No Solution\n");
            exit(0);
        }
        if (r != i) {
            for (int j = 0; j <= n; j++) {
                swap(A[r][j], A[i][j]);
            }
        }
        for (int k = 0; k < n; k++) {
            if (k != i) {
                for (int j = n; j >= i; j--) {
                    A[k][j] -= A[k][i] / A[i][i] * A[i][j];
                }
            }
        }
    }
}

void print(Matrix a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("%.2lf ", a[i][j]);
        }
        puts("");
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
    Gauss_jordan(A, n);
    // print(A, n);
    for (int i = 0; i < n; ++i) {
        printf("%.2f\n", A[i][n] / A[i][i]);
    }
    return 0;
}