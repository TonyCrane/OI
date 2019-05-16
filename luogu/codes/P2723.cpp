
/*************************************************************
 *  > File Name        : P2723.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/16 12:41:08
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxk = 110;
const int maxn = 100010;

long long k, n, a[maxk], i, t, s[maxn], b[maxk];

int main() {
    scanf("%lld %lld", &k, &n);
    for (long long i = 1; i <= k; ++i) {
        scanf("%lld", &a[i]);
    }
    s[0] = 1;
    for (long long i = 1; i <= n; ++i) {
        long long minn = 0x3f3f3f3f;
        for (long long j = 1; j <= k; ++j) {
            while (a[j] * s[b[j]] <= s[i - 1]) {
                b[j]++;
            }
            if (a[j] * s[b[j]] < minn) {
                minn = a[j] * s[b[j]];
            }
        }
        s[i] = minn;
    }
    printf("%lld\n", s[n]);
    return 0;
}