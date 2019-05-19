/*************************************************************
 *  > File Name        : P4781.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/19 15:15:59
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int p = 998244353;
int x[2010], y[2010];

inline int pow_mod(int a, int b, int n){
    int res = 1;
    while (b) {
        if (b & 1) res = 1LL * res * a % n;
        a = 1LL * a * a % n;
        b >>= 1;
    }
    return res;
}

inline int inv(int n) {
    return pow_mod(n % p, p - 2, p);
}

int main() {
    int n = read(), k = read();
    for (int i = 1; i <= n; ++i) {
        x[i] = read(); y[i] = read();
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 1;
        for (int j = 1; j <= n; ++j) {
            if (j != i) {
                cnt = (1LL * cnt * (k - x[j]) % p * inv(x[i] - x[j])) % p;
            }
        }
        ans = (ans + 1LL * cnt * y[i] % p) % p;
    }
    printf("%d\n", (ans + p) % p);
    return 0;
}