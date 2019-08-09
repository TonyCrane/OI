/*************************************************************
 *  > File Name        : 1134.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 17:18:57
 *  > Algorithm        : 模拟
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, k;

int main() {
    n = read(); k = read();
    if (k > n) {
        puts("-1");
        return 0;
    }
    if (k == 1) {
        if (n > 1) {
            puts("-1");
        } else {
            puts("a");
        }
    } else if (k == 2) {
        for (int i = 1; i <= n; ++i) {
            if (i % 2) printf("a");
            else printf("b");
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n - k + 2; ++i) {
            if (i % 2) printf("a");
            else printf("b");
        }
        for (int i = 2; i < k; ++i) {
            putchar('a' + i);
        }
        printf("\n");
    }
    return 0;
}