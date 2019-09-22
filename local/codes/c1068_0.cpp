/*************************************************************
 *  > File Name        : c1068_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/22 12:14:45
 *  > Algorithm        : math
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

const int maxn = 100010;

LL n, p, a[maxn], ans, sum[maxn], need, mark;
bool cmp(LL a, LL b) { return a > b; }

int main() {
    n = read();
    for (LL i = 1; i <= n; ++i) {
        a[i] = read();
        p += a[i];
    }
    for (LL i = 2; i <= sqrt(p); ++i) {
        if (p % i == 0) {
            p = i;
            break;
        }
    }
    for (LL i = 1; i <= n; ++i) a[i] %= p;
    sort(a + 1, a + 1 + n, cmp);
    for (LL i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (LL i = 1; i <= n; ++i) {
        if (need == sum[n] - sum[i - 1]) {
            printf("%lld\n", need);
            return 0;
        } else {
            need += p - a[i];
        }
    }
}