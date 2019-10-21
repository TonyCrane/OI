/*************************************************************
 *  > File Name        : CF1248B.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/21 17:08:26
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0; long long f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const long long maxn = 100010;

long long a[maxn], len, wid;

int main() {
    long long n = read();
    for (long long i = 1; i <= n; ++i) {
        a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    for (long long i = 1; i <= n / 2; ++i) {
        wid += a[i];
    }
    for (long long i = n / 2 + 1; i <= n; ++i) {
        len += a[i];
    }
    printf("%lld\n", wid * wid + len * len);
    return 0;
}