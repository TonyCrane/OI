/*************************************************************
 *  > File Name        : P1134.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/16 16:26:26
 *  > Algorithm        : Math
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, ans = 1, a[4] = {6, 8, 4, 2};

int main() {
    n = read();
    while (n > 0) {
        for (int i = 1; i <= n % 10; ++i) {
            if (i != 5) {
                ans *= i;
                ans %= 10;
            }
        }
        n /= 5;
        ans *= a[n % 4]; ans %= 10;
    }
    printf("%d\n", ans);
    return 0;
}