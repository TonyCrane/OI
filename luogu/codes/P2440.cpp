/*************************************************************
 *  > File Name        : P2440.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/01 10:59:32
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[100010], sum, n, k, ans;

bool judge(int x) {
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        num += a[i] / x;
        if (num >= k) return true;
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum < k) {
        printf("0\n");
        return 0;
    }
    int l = 0, r = sum / n;
    while (l <= r) {
        int mid = (l + r) / 2 + rand() % 2;
        if (judge(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}