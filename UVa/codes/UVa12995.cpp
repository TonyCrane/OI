/*************************************************************
 *  > File Name        : UVa12995.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/07 15:51:27
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;

long long phi[maxn];
void phi_table() {
    for (int i = 2; i <= 1000000; ++i) phi[i] = 0; phi[1] = 1;
    for (int i = 2; i <= 1000000; ++i) {
        if (!phi[i]) for (int j = i; j <= 1000000; j += i) {
            if (!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i - 1);
        }
        phi[i] += phi[i - 1];
    }
}

int main() {
    phi_table();
    int n;
    while (cin >> n) {
        if (n == 0) break;
        printf("%lld\n", phi[n] - 1);
    }
    return 0;
}