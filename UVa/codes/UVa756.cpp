/*************************************************************
 *  > File Name        : UVa756.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/08 15:55:17
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int p, e, i, d, kase = 0;
int m[3] = {23, 28, 33}, a[3];

void exgcd(int a, int b, int& d, int& x, int& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}


int crt(int n, int* a, int* m) {
    int M = 1, gcd, y, x = 0, tmp;
    for (int i = 0; i < n; ++i) M *= m[i];
    for (int i = 0; i < n; ++i) {
        int w = M / m[i];
        exgcd(m[i], w, gcd, tmp, y);
        x = (x + y * w * a[i]) % M;
    }
    if (x <= d) return 21252 - (d - x);
    else return x - d;
}

int main() {
    while (scanf("%d %d %d %d", &p, &e, &i, &d) == 4 && p != -1) {
        kase++;
        a[0] = p % m[0];
        a[1] = e % m[1];
        a[2] = i % m[2];
        int ans = crt(3, a, m);
        printf("Case %d: the next triple peak occurs in %d days.\n", kase, ans);
    }
    return 0;
}