/*************************************************************
 *  > File Name        : P1414.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/16 16:17:59
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

const int maxn = 1000010;

int n, maxx, a[maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read();
        maxx = max(maxx, x);
        int xx = sqrt(x);
        for (int j = 1; j <= xx; ++j) {
            if (x % j == 0) {
                a[j]++;
                if (x != j * j) {
                    a[x / j]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        while (a[maxx] < i) {
            maxx--;
        }
        printf("%d\n", maxx);
    }
    return 0;
}