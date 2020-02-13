/*************************************************************
 *  > File Name        : c1000_6.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/15 12:22:34
 *  > Algorithm        : gcd
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}