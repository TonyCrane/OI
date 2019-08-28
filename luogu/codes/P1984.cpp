/*************************************************************
 *  > File Name        : P1984.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/28 15:27:09
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

int n;
double ans, now;

int main() {
    n = read();
    now = 420000.00 / n;
    for (int i = 1; i <= n; ++i) {
        ans += now;
        now *= (1 - 0.5 / i);
    }    
    printf("%.2lf\n", ans);
    return 0;
}