/*************************************************************
 *  > File Name        : nc1000_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/13 12:29:22
 *  > Algorithm        : digui
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

long long n, ans;

void solve(int l, int r) {
    if (l == r) return;
    if (l + 1 == r) {
        ans += l * r;
        return;
    }
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
}

int main() {
    scanf("%lld", &n);
    solve(1, n);
    printf("%lld\n", ans);
    return 0;
}