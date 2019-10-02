/*************************************************************
 *  > File Name        : P1288.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/02 18:12:03
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

const int maxn = 25;

int n, a[maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            if (i % 2 == 0) {
                printf("YES\n");
                return 0;
            } else break;
        }
    }
    for (int i = n; i >= 1; --i) {
        if (a[i] == 0) {
            if ((n - i + 1) % 2 == 0) {
                printf("YES\n");
                return 0;
            } else break;
        }
    }
    printf("NO\n");
    return 0;
}