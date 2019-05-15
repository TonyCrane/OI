/*************************************************************
 *  > File Name        : P2312.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/15 14:41:43
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int p = 1e8 + 7;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = (x * 10 + ch - 48) % p; ch = getchar();}
    return x * f;
}

int a[110], ans[110], ansi;

int main() {
    int n = read(), m = read();
    for (int i = 0; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) {
        int sum = 0;
        for (int j = n; j >= 0; --j) {
            sum = (1ll * sum * i + a[j]) % p;
        }
        if (sum == 0) ans[++ansi] = i;
    }
    printf("%d\n", ansi);
    for (int i = 1; i <= ansi; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}