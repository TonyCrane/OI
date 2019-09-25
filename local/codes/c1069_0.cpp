/*************************************************************
 *  > File Name        : c1069_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/25 12:36:29
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull T, n;

int main() {
    scanf("%llu", &T);
    while (T--) {
        scanf("%llu", &n);
        if (n == 0) {
            printf("1\n");
        } else if (n == 1) {
            printf("9\n");
        } else if (n == 2) {
            printf("41\n");
        } else if (n == 3) {
            printf("109\n");
        } else if (n == 4) {
            printf("205\n");
        } else if (n == 5) {
            printf("325\n");
        } else {
            printf("%llu\n", (ull)(n - 5) * (64 + (ull)14 * n) + 325LLU);
        }
    }
    return 0;
}