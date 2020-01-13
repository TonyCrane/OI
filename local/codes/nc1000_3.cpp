/*************************************************************
 *  > File Name        : nc1000_3.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/13 12:44:30
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

int n, k;

int solve(int n) {
    if ((n - k) / 2 <= 0) return 1;
    if ((n - k) % 2 == 1) return 1;
    return solve((n - k) / 2) + solve((n + k) / 2);
}

int main() {
    n = read(); k = read();
    printf("%d\n", solve(n));
    return 0;
}