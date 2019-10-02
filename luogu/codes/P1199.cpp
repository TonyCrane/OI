/*************************************************************
 *  > File Name        : P1199.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/02 15:49:13
 *  > Algorithm        : Greedy
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 510;

int a[maxn][maxn], ans;

int main() {
    int n = read();
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            a[i][j] = a[j][i] = read();
        }
    }
    for (int i = 1; i <= n; ++i) {
        sort(a[i] + 1, a[i] + 1 + n);
        ans = max(ans, a[i][n - 1]);
    }
    printf("1\n%d\n", ans);
    return 0;
}