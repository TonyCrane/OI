/*************************************************************
 *  > File Name        : c1066_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/17 12:42:15
 *  > Algorithm        : math-gcd
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * (LL)f;
}

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL a, b, c;

int main() {
    a = read(), b = read(), c = read();
    LL ab = a * b / gcd(a, b);
    printf("%lld\n", ab * c / gcd(ab, c));
    return 0;
}