/*************************************************************
 *  > File Name        : P1226.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/07 15:29:41
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL b, p, k;

LL pow_mod(LL a, LL p, LL n) {
    if (p == 0 && n == 1) return 0;
    if (p == 0) return 1;
    LL ans = pow_mod(a, p / 2, n); ans = ans * ans % n;
    if (p % 2 == 1) ans = ans * a % n;
    return ans;
}

int main() {
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld", b, p, k, pow_mod(b, p, k));
    return 0;
}