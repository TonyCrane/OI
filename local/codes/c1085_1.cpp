/*************************************************************
 *  > File Name        : c1085_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/06 20:32:13
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

const LL maxn = 1000010;

LL n, m, a[maxn], ans, bit[32], l = 1, r = 0;
LL q[maxn];

int main() {
    n = read(); m = read();
    for (LL i = 1; i <= n; ++i) a[i] = read();
    for (LL i = 1; i <= n; ++i) {
        LL ai = a[i]; LL cnt = 0;
        while (ai != 0) {
            if (ai & 1) bit[cnt]++;
            ai >>= 1; cnt++;
        }
        LL now = 0;
        for (LL j = 0; j <= 30; ++j) {
            if (bit[j]) now += (1 << j);
        }
        q[++r] = a[i];
        while (now >= m && l <= r) {
            LL head = q[l]; cnt = 0;
            while (head != 0) {
                if (head & 1) bit[cnt]--;
                head >>= 1; cnt++;
            }
            now = 0;
            for (LL j = 0; j <= 30; ++j) {
                if (bit[j]) now += (1 << j);
            }
            l++;
        }
        ans += max((r - l), 0LL);
    }
    printf("%lld\n", ans);
    return 0;
}