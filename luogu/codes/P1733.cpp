/*************************************************************
 *  > File Name        : P1733.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/05/08 07:42:58
 *  > Algorithm        : 交互 二分
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int l = 1, r = 1000000000, mid, res;

int main() {
    while (l <= r) {
        mid = (l + r) >> 1;
        printf("%d\n", mid);
        fflush(stdout);
        scanf("%d", &res);
        if (res == 0) {
            return 0;
        } else if (res == 1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}