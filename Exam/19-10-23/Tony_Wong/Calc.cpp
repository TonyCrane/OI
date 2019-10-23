/*************************************************************
 *  > File Name        : Calc.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/23 12:21:37
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define debug(x) cout << #x << " = " << x << endl

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

LL pow_mod(LL a, LL p, LL n){
    LL res = 1;
    while (p) {
        if (p & 1) res = 1 * res * a % n;
        a = 1 * a * a % n;
        p >>= 1;
    }
    return res;
}

LL n, k, len, tot, ans;
LL F[maxn], G[maxn];
LL all[maxn * 2], old[maxn * 2], t[maxn * 10];

void add(LL x, LL k) {
    for (; x <= len; x += x & -x) t[x] += k;
}

LL ask(LL x) {
    LL res = 0;
    for (; x; x -= x & -x) res += t[x];
    return res;
}

int main() {
    freopen("Calc.in", "r", stdin);
    freopen("Calc.out", "w", stdout);
    n = read(); k = read();
    for (LL i = 1; i <= n; ++i) {
        LL a = read();
        F[i] = pow_mod(i, a, k);
        G[i] = pow_mod(a, i, k);
        all[++tot] = F[i]; old[tot] = all[tot];
        all[++tot] = G[i]; old[tot] = all[tot];
    }
    sort(old + 1, old + 1 + tot);
    len = unique(old + 1, old + 1 + tot) - old - 1;
    for (LL i = 1; i <= n; ++i) {
        F[i] = lower_bound(old + 1, old + 1 + len, F[i]) - old;
        G[i] = lower_bound(old + 1, old + 1 + len, G[i]) - old;
    }
    for (LL i = n; i; --i) {
        ans += ask(F[i] - 1);
        add(G[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}