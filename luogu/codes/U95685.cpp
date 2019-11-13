/*************************************************************
 *  > File Name        : U95685.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 16:06:24
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

const int maxn = 1000010;

int main() {
    srand((int)time(NULL));
    int n = read();
    printf("%d\n", rand() % (3 * n));
    return 0;
}