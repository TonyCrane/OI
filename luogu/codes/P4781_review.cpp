/*************************************************************
 *  > File Name        : P4781_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/12/06 12:28:41
 *  > Algorithm        : review Lagrange
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2010;
const int mod  = 998244353;

int n, x[maxn], y[maxn], k;
int ans;

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

int main() {
    n = read(); k = read();
    for (int i = 0; i < n; ++i) x[i] = read(), y[i] = read();
    for (int i = 0; i < n; ++i) {
        long long tmp = 1;
        for (int j = 0; j < n; ++j) if (j != i) tmp = tmp * (x[i] - x[j] + mod) % mod;
        tmp = inv(tmp);
        for (int j = 0; j < n; ++j) if (j != i) tmp = tmp * (k - x[j] + mod) % mod;
        tmp = tmp * y[i] % mod;
        ans = (ans + tmp) % mod;
    }
    printf("%d\n", ans);
    return 0;
}