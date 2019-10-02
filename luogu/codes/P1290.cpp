/*************************************************************
 *  > File Name        : P1290.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/02 18:28:10
 *  > Algorithm        : 博弈
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int m, n;

bool SG(int m, int n) {
    if (!n) return false;
    if (m / n == 1) return !SG(n, m % n);
    return true;
}

int main() {
    int T = read();
    while (T--) {
        m = read(); n = read();
        if (m < n) swap(n, m);
        printf(SG(m, n) ? "Stan wins\n" : "Ollie wins\n");
    }
    return 0;
}