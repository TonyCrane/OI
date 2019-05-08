/*************************************************************
 *  > File Name        : P1516.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/08 15:35:02
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

int main() {
    LL n, m, x, y, l, gcd, x1, y1;
    scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
    LL b = n - m, a = x - y;
    if (b < 0) { b = -b, a = -a; }
    exgcd(b, l, gcd, x1, y1);
    if (a % gcd) {
        printf("Impossible\n");
    } else {
        LL ans = ((x1 * (a / gcd)) % (l / gcd) + (l / gcd)) % (l / gcd);
        printf("%lld\n", ans);
    }
    return 0;
}