/*************************************************************
 *  > File Name        : P2842.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/10 16:14:51
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1e9 + 7;

LL a, b;

LL pow_mod(LL a, LL p, LL mod) {
    a %= mod; LL ans = 1;
    for (; p; p >>= 1, a *= a, a %= mod) if(p & 1) ans = ans * a % mod;
    return ans;
}

int main() {
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", pow_mod(a, pow_mod(a, b - 1, mod - 1), mod));
    return 0;
}