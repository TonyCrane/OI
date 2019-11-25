/*************************************************************
 *  > File Name        : P5657_2.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/23 16:30:25
 *  > Algorithm        : code正解
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long k;

int main() {
    scanf("%d %llu", &n, &k);
    k ^= (k >> 1);
    while (n--) {
        printf("%d", (k >> n & 1));
    }
    puts("");
    return 0;
}