/*************************************************************
 *  > File Name        : P3811.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/07 15:15:24
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3000010;

int inv[maxn];
void getinv(int n, int p) {
    inv[1] = 1; printf("1\n");
    for (int i = 2; i <= n; ++i) {
        inv[i] = (LL)(p - p / i) * inv[p % i] % p;
        printf("%d\n", inv[i]);
    }
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    getinv(n, p);
    return 0;
}