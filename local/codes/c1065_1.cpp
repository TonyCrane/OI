/*************************************************************
 *  > File Name        : c1065_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/16 12:44:10
 *  > Algorithm        : mod
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

LL a[maxn], ans, n, k;

int main() {
    n = read(); k = read();
    for (LL i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (int i = 1; i <= k; ++i) {
        LL cnt = 0, minn = 0x3f3f3f3f;
        for (int j = i; j <= n; j += k) {
            cnt += 1; ans += a[j];
            if (cnt % 2 == 1) {
                minn = min(minn, a[j]);
            }
        }
        if (cnt % 2 == 1) {
            ans -= minn;
        }
    }
    printf("%lld\n", ans);
    return 0;
}