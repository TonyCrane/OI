/*************************************************************
 *  > File Name        : P2261.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/11 12:41:36
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long n, k, ans;

int main() {
    scanf("%lld %lld", &n, &k);
    for (long long l = 1, r, t; l <= n; l = r + 1) {
        t = k / l;
        if (t) r = min(k / t, n);
        else r = n;
        ans += t * (r - l + 1) * (l + r) / 2;
    }
    printf("%lld\n", n * k - ans);
    return 0;
}