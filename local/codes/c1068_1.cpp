/*************************************************************
 *  > File Name        : c1068_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/22 15:09:20
 *  > Algorithm        : 数位
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

int main() {
    LL T = read();
    while (T--) {
        LL n = read();
        LL tmp = n, len = 0;
        while (tmp) {
            len++;
            tmp /= 10;
        }
        bool ok = false;
        for (LL i = max(0LL, n - 9 * len); i <= n; ++i) {
            LL sum = i; tmp = i;
            while (tmp) {
                sum += tmp % 10;
                tmp /= 10;
            }
            if (sum == n) {
                printf("%lld\n", i);
                ok = true;
                break;
            }
        }
        if (!ok) {
            printf("Stupid SiriusRen\n");
        }
    }
    return 0;
}