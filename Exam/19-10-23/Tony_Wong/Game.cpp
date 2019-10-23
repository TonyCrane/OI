/*************************************************************
 *  > File Name        : Game.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/23 13:03:08
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

const LL maxn = 500010;

LL n, r, k, ans;
LL a[maxn], sum[maxn], defence[maxn];
LL add[maxn];

bool check(LL x) {
    memset(add, 0, sizeof(add));
    LL ddefence = 0, rest = k;
    for (LL i = 1; i <= n; ++i) {
        if (i > r) ddefence -= add[i - r - 1];
        if (defence[i] + ddefence >= x) continue;
        LL need = x - defence[i] - ddefence;
        LL R = i + r; if (R > n) R = n;
        add[R] += need;
        rest -= need;
        ddefence += need;
        if (rest < 0) return false;
    }
    return true;
}

int main() {
    // freopen("Game.in", "r", stdin);
    // freopen("Game.out", "w", stdout);
    n = read(); r = read(); k = read();
    for (LL i = 1; i <= n; ++i) {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    LL le = 0, ri = 0, mid;
    for (LL i = 1; i <= n; ++i) {
        LL L = i - r, R = i + r;
        if (L < 1) L = 1;
        if (R > n) R = n;
        defence[i] = sum[R] - sum[L - 1];
        ri = max(ri, defence[i] + k);
    }
    while (le <= ri) {
        mid = (le + ri) >> 1;
        if (check(mid)) {
            ans = mid;
            le = mid + 1;
        } else ri = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}