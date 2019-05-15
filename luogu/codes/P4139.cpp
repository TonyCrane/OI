/*************************************************************
 *  > File Name        : P4139.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 16:02:03
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e7 + 20;

LL pow_mod(LL a, LL p, LL n) {
    a %= n; LL ans = 1;
    for (; p; p >>= 1, a *= a, a %= n)
        if(p & 1) ans = ans * a % n;
    return ans;
}

int phi[maxn];
void phi_table(int n) {
    for (int i = 2; i <= n; ++i) phi[i] = 0; phi[1] = 1;
    for (int i = 2; i <= n; ++i) if (!phi[i])
        for (int j = i; j <= n; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
}

LL solve(int p) {
    if (p == 1) return 0;
    return pow_mod(2, solve(phi[p]) + phi[p], p);
}

int main() {
    phi_table(maxn - 20);
    int T; scanf("%d", &T);
    while (T--) {
        LL p;
        scanf("%lld", &p);
        if (p == 1) {
            printf("0\n");
        } else {
            printf("%lld\n", solve(p));
        }
    }
    return 0;
}