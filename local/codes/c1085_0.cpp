/*************************************************************
 *  > File Name        : c1085_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/06 16:38:36
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

int n, q, l, r;

int main() {
    n = read(); q = read(); l = 1; r = n;
    while (l < r) {
        double mid = (l + r) / 2.0;
        int m = (l + r) >> 1;
        if ((double)q >= mid) {
            q = 2 * mid - q;
            r = m;
        } else {
            q = 2 * mid - q;
            l = m + 1;
        }
    }
    printf("%d\n", q);
    return 0;
}