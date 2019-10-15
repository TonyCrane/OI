/*************************************************************
 *  > File Name        : P5367.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/15 16:05:39
 *  > Algorithm        : [math]Cantor
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

const int maxn = 1000010;
const int mod  = 998244353;

int n, a, t[maxn];
LL tab[maxn], ans;

void add(int x, int k) {
    for (; x <= n; x += x & -x) t[x] += k;
}

int ask(int x) {
    int res = 0;
    for (; x; x -= x & -x) res += t[x];
    return res;
}

int main() {
    n = read(); tab[0] = 1;
    for (int i = 1; i <= n; ++i) tab[i] = tab[i - 1] * i % mod;
    for (int i = 1; i <= n; ++i) add(i, 1);
    for (int i = 1; i <= n; ++i) {
        a = read();
        ans += (LL)(ask(a) - 1) * tab[n - i];
        ans %= mod;
        add(a, -1);
    }
    printf("%lld\n", ans + 1);
    return 0;
}