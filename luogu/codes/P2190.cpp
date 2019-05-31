/*************************************************************
 *  > File Name        : P2190.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/31 16:25:32
 *  > Algorithm        : [Simulation]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n, m, ans, p, x, y, z, tx[2000100], ty[2000100];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        if (x < y) tx[x] += z;
        else {
            tx[1] += z;
            tx[x] += z;
        }
        ty[y] += z;
    }
    for (int i = 1; i <= 1000000; i++) {
        p += tx[i];
        p -= ty[i];
        ans = max(ans, p);
    }
    if (ans % 36 != 0) printf("%d\n", ans / 36 + 1);
    else printf("%d", ans / 36);
    return 0;
}