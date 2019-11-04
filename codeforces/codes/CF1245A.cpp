/*************************************************************
 *  > File Name        : CF1245A.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/04 12:57:55
 *  > Algorithm        : gcd
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
        int a = read(), b = read();
        if (gcd(a, b) == 1) printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}