/*************************************************************
 *  > File Name        : P6476.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/25 14:06:49
 *  > Algorithm        : math
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int T = read();
    while (T--) {
        int p1 = read(), p2 = read(), k = read();
        if (p1 > p2) swap(p1, p2);
        if (k == 1) {printf("No\n"); continue;}
        int g = gcd(p1, p2);
        p1 /= g; p2 /= g;
        if (p2 > 2 && (p2 - 2) / p1 + 1 >= k) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}