/*************************************************************
 *  > File Name        : CF622F.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/12/06 12:48:29
 *  > Algorithm        : Lagrange
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;
const int mod  = 1e9 + 7;

int pow_mod(int a, int p, int n){
    int res = 1;
    while (p) {
        if (p & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        p >>= 1;
    }
    return res;
}

int inv(int x) {
    return pow_mod(x % mod, mod - 2, mod);
}

int n, k, x[maxn], y[maxn];
long long ans = 0;

int main() {
    n = read(); k = read();
    
    printf("%lld\n", ans);
    return 0;
}