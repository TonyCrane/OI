/*************************************************************
 *  > File Name        : nc1000_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/13 12:38:39
 *  > Algorithm        : digui
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110;

int n, arr[maxn], num;

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) arr[i] = read();
    num = read();
    for (int i = 1; i <= n; ++i) {
        if (arr[i] == num) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}