/*************************************************************
 *  > File Name        : P1314.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/17 20:55:14
 *  > Algorithm        : preres
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

const LL maxn = 2000010;
const LL inf  = 0x3f3f3f3f3f3f3f3f;

LL n, m, s, res, ans = inf;
LL w[maxn], v[maxn], L[maxn], R[maxn], preV[maxn], pren[maxn];

inline bool check(LL x) {
    memset(preV, 0, sizeof(preV));
    memset(pren, 0, sizeof(pren));
    for (LL i = 1; i <= n; ++i) {
        if (w[i] >= x) {
            preV[i] = preV[i - 1] + v[i];
            pren[i] = pren[i - 1] + 1;
        } else {
            preV[i] = preV[i - 1];
            pren[i] = pren[i - 1];
        }
    }
    LL Y = 0;
    for (LL i = 1; i <= m; ++i) {
        Y += (pren[R[i]] - pren[L[i] - 1]) * (preV[R[i]] - preV[L[i] - 1]);
    }
    res = abs(Y - s);
    if (Y > s) return true;
    else return false;
}

int main() {
    n = read(); m = read(); s = read();
    LL l = inf, r = 0;
    for (LL i = 1; i <= n; ++i) {
        w[i] = read(); v[i] = read();
        r = max(r, w[i]);
        l = min(l, w[i]);
    }
    for (LL i = 1; i <= m; ++i) {
        L[i] = read(); R[i] = read();
    }
    l--; r++; r++;
    while (l <= r) {
        LL mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
        ans = min(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}