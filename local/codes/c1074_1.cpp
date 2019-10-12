/*************************************************************
 *  > File Name        : c1074_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/12 16:00:02
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

const int maxn = 2000010;

int n, m, a[maxn], b[maxn], c[maxn * 2], lastans;

void work() {
    int i = 1, j = 1, k = 1;
    while (i <= n && j <= n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i <= n) c[k++] = a[i++];
    while (j <= n) c[k++] = b[j++];
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) b[i] = read();
    work();
    for (int i = 1; i <= m; ++i) {
        int x = (read() ^ lastans) % (2 * n) + 1;
        printf("%d\n", lastans = c[x]);
    }
    return 0;
}