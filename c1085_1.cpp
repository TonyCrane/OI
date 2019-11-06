/*************************************************************
 *  > File Name        : c1085_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/06 20:32:13
 *  > Algorithm        : 30分暴力
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;

int n, m, a[maxn], ans, bit[32], l, r = 1;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (l = 1; l <= n; ++l) {
        while (r <= n) {
            int now = 0;
            for (int i = 31; i >= 0; --i) {
                if (bit[i]) now += (1 << i);
            }
            // printf("now = %d, l = %d, r = %d\n", now, l, r);
            if (now >= m) {
                ans += r - 1 - l;
                bitset<32> b = bitset<32>(a[l]);
                for (int i = b.size() - 1; i >= 0; --i) {
                    bit[i] -= b[i];
                }
                break;
            }
            r++;
            bitset<32> b = bitset<32>(a[r]);
            for (int i = b.size() - 1; i >= 0; --i) {
                bit[i] += b[i];
            }
            if (r == n) {
                ans += r - l;
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    return 0;
}