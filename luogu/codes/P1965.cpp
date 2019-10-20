/*************************************************************
 *  > File Name        : P1965.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 19:22:19
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

int pow_mod(int a, int p, int n){
    int res = 1;
    while (p) {
        if (p & 1) res = 1 * res * a % n;
        a = 1 * a * a % n;
        p >>= 1;
    }
    return res;
}

int main() {
    int n = read(), m = read(), k = read(), x = read();
    printf("%d\n", (x % n + m % n * pow_mod(10, k, n) % n) % n);
    return 0;
}