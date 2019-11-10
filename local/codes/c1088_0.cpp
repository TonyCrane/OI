/*************************************************************
 *  > File Name        : c1088_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/10 12:31:56
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

LL phi(LL n) {
    LL m = (LL)sqrt(n + 0.5); LL ans = n;
    for (LL i = 2; i <= m; ++i) if (n % i == 0) {
        ans = ans / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

int main() {
    LL n = read();
    printf("%lld\n", phi(n));
    return 0;
}