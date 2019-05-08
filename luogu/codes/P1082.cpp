/*************************************************************
 *  > File Name        : P1082.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/08 15:24:37
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

LL inv(LL a, LL n) {
    LL d, x, y;
    exgcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

int main() {
    LL a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", inv(a, b));
}