/*************************************************************
 *  > File Name        : P4783.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/18 00:14:50
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;
const int maxn = 410;

long long a[maxn][maxn];
int n, is[maxn], js[maxn];

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

LL inv(LL a, LL n) {
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

void inv() {
    for (int k = 1; k <= n; ++k) {
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                if (a[i][j]) {
                    is[k] = i; js[k] = j; break;
                }
            }
        }
        for (int i = 1; i <= n; ++i) swap(a[k][i], a[is[k]][i]);
        for (int i = 1; i <= n; ++i) swap(a[i][k], a[i][js[k]]);
        if (!a[k][k]) {
            printf("No Solution\n");
            exit(0);
        }
        a[k][k] = inv(a[k][k], mod);
        for (int j = 1; j <= n; ++j)
            if (j != k) (a[k][j] *= a[k][k]) %= mod;
        for (int i = 1; i <= n; ++i)
            if (i != k) for (int j = 1; j <= n; ++j)
                if (j != k) (a[i][j] += mod - a[i][k] * a[k][j] % mod) %= mod;
        for (int i = 1; i <= n; ++i) 
            if (i != k) a[i][k] = (mod - a[i][k] * a[k][k] % mod) % mod;
    }
    for (int k = n; k; --k) {
        for (int i = 1; i <= n; ++i) swap(a[js[k]][i], a[k][i]);
        for (int i = 1; i <= n; ++i) swap(a[i][is[k]], a[i][k]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }
    inv();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%lld ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}