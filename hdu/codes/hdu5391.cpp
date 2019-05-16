/*************************************************************
 *  > File Name        : hdu5391.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/16 16:11:02
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        if (n == 4) printf("2\n");
        else {
            if (isprime(n)) {
                printf("%d\n", n - 1);
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}