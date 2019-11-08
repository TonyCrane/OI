/*************************************************************
 *  > File Name        : c1087_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/08 14:57:33
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

int n;

int main() {
    int T = read();
    while (T--) {
        n = read();
        if (n % 3 == 0) {
            long long a = n / 3;
            printf("%lld\n", a * a * a);
            continue;
        }
        if (n % 4 == 0) {
            long long a1 = n / 2;
            long long a2 = n / 4;
            printf("%lld\n", a1 * a2 * a2);
            continue;
        }
        printf("-1\n");
    }
    return 0;
}