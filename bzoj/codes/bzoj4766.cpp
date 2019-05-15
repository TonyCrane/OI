/*************************************************************
 *  > File Name        : bzoj4766.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 15:10:33
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL mul_mod(LL a, LL b, LL n){
    LL res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % n;
        a = (a << 1) % n;
        b >>= 1;
    }
    return res;
}

LL pow_mod(LL a, LL p, LL n) {
    LL res = 1;
    while (p) {
        if (p & 1)
            res = mul_mod(res, a, n);
        a = mul_mod(a, a, n);
        p >>= 1;
    }
    return res;
}

int main() {
    LL n, m, p;
    scanf("%lld %lld %lld", &n, &m, &p);
    if (n == 0 || m == 0) {
        printf("0\n");
        return 0;
    }
    printf("%lld\n", mul_mod(pow_mod(n, m - 1, p), pow_mod(m, n - 1, p), p));
    return 0;
}