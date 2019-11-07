/*************************************************************
 *  > File Name        : CF1243A.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/07 20:48:11
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

int n, a[maxn], ans;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        for (int i = 1; i <= n; ++i) a[i] = read();
        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= i) {
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}