/*************************************************************
 *  > File Name        : CF1A.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 20:49:58
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

LL n, m, a;

int main() {
    n = read(); m = read(); a = read();
    printf("%lld\n", (long long)(ceil(n / (double)a) * ceil(m / (double)a)));
    return 0;
}