/*************************************************************
 *  > File Name        : CF1248A.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/21 16:43:01
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

int main() {
    long long T = read();
    while (T--) {
        long long n = read(), p0 = 0, p1 = 0, q0 = 0, q1 = 0;
        for (long long i = 1; i <= n; ++i) {
            long long p = read();
            if (p % 2 == 0) p0++;
            else p1++;
        }
        long long m = read();
        for (long long i = 1; i <= m; ++i) {
            long long q = read();
            if (q % 2 == 0) q0++;
            else q1++;
        }
        printf("%lld\n", p0 * q0 + p1 * q1);
    }
    return 0;
}