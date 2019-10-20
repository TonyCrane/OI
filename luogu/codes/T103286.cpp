/*************************************************************
 *  > File Name        : T103286.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 15:06:09
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

int a, b, x, y;

int main() {
    a = read(); b = read();
    if (a == 0 && b == 0) {
        printf("inf\n");
    } else if (a == 0) {
        if (b % 2 != 0 || b % 4 == 0) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}