/*************************************************************
 *  > File Name        : T103284.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/20 14:06:54
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

int n, m, k, a[maxn][maxn];
set<int> b[maxn];

int main() {
    n = read(); m = read(); k = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = read();
            b[a[i][j]].insert(j);
        }
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d ", b[i].size());
    }
    return 0;
}