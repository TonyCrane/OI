/*************************************************************
 *  > File Name        : CF1248C.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/21 20:45:20
 *  > Algorithm        : math
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;
const int mod  = 1e9 + 7;

LL F[maxn];

int main() {
    int n = read(), m = read();
    F[1] = F[0] = 1;
    for (int i = 2; i <= max(m, n); ++i) {
        F[i] = (F[i - 1] + F[i - 2]) % mod;
    }
    printf("%lld\n", ((F[n] + F[m] - 1) % mod) * 2 % mod);
    return 0;
}