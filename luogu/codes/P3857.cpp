/*************************************************************
 *  > File Name        : P3857.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/13 14:38:06
 *  > Algorithm        : 线性基
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 60;

int n, m, res;
LL a[maxn], p[maxn];

bool insert(LL x) {
    for (int i = 61; i >= 0; --i) {
        if (x & (1LL << i)) {
            if (p[i]) x ^= p[i];
            else {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        char s[maxn];
        scanf("%s", s);
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'O') a[i] ^= (1LL << (n - j - 1));
        }
        // printf("%lld\n", a[i]);
        if (insert(a[i])) {
            res++;
        }
    }
    printf("%lld\n", (1LL << res) % 2008);
    return 0;
}