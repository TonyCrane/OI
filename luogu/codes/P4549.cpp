/*************************************************************
 *  > File Name        : P4549.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/08 15:31:10
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        if (a < 0) a = -a;
        ans = gcd(ans, a);
    }
    printf("%d", ans);
    return 0;
}