/*************************************************************
 *  > File Name        : 1128.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/08 17:15:10
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

const int maxn = 1000010;

int n, m, arr[maxn], ans;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        int ai = read(), bi = read(), ci = read();
        arr[ai] += ci;
        arr[bi] -= ci;
    }
    for (int i = 1; i <= n; ++i) {
        if (arr[i] > 0) {
            ans += arr[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}