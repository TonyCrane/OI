/*************************************************************
 *  > File Name        : c1083_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/01 15:43:52
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, m;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    n = read(); m = read();
    printf("%d\n", m - gcd(n, m));
    return 0;
}