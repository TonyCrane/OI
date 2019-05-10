/*************************************************************
 *  > File Name        : P5091.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/10 15:54:33
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL phi(LL n) {
    LL m = (LL)sqrt(n + 0.5); LL ans = n;
    for (LL i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

LL pow_mod(LL a, LL p, LL n) {
    if (p == 0 && n == 1) return 0;
    if (p == 0) return 1;
    LL ans = pow_mod(a, p / 2, n); ans = ans * ans % n;
    if (p % 2 == 1) ans = ans * a % n;
    return ans;
}

LL a, m, b;

int main() {
    scanf("%lld %lld", &a, &m);
    LL mm = phi(m);
    LL x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        if (x >= mm) f = 1;
        x %= mm; ch = getchar();
    }
    b = x + (f == 1? mm : 0);
    printf("%lld\n", pow_mod(a, b, m));
    return 0;
}