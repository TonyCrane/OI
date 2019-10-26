/*************************************************************
 *  > File Name        : CF1247C.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 20:06:37
 *  > Algorithm        : -
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

LL n, p;
bitset<32000> b;

int main() {
    n = read(); p = read();
    for (LL i = 1; i <= 999999999; ++i) {
        if (n - i * p < 0) {
            printf("-1\n");
            return 0;   
        }
        b = bitset<32000>(n - i * p);
        if (b.count() <= i && b.count() > 0) {
            printf("%I64d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}