/*************************************************************
 *  > File Name        : SP104.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/19 12:36:33
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
const double eps = 1e-8;
double A[maxn][maxn];
int n, d, m;

void Gauss() {
    int r; n--;
    for (int i = 0; i < n; ++i) {
        r = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        }
        if (fabs(A[r][i]) < eps) {
            printf("0\n");
            return;
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
    double ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= A[i][i];
    }
    printf("%.0f\n", abs(ans));
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        memset(A, 0, sizeof(A));
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            int x, y; scanf("%d %d", &x, &y);
            A[--x][x]++; A[--y][y]++;
            A[x][y]--  ; A[y][x]--  ;
        }
        Gauss();
    }
    return 0;
}