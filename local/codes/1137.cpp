/*************************************************************
 *  > File Name        : 1137.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 17:46:44
 *  > Algorithm        : LIS
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 300010;

int a[maxn], l[maxn], r[maxn];

int main() {
    int n = read(), ans = 0, tmp = 0;
    a[0] = 0; a[n + 1] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) {
            tmp++;
            l[i] = tmp;
        } else {
            tmp = 1;
            l[i] = tmp;
        }
    }
    tmp = 0;
    for (int i = n; i >= 1; --i) {
        if (a[i] < a[i + 1]) {
            tmp++;
            r[i] = tmp;
        } else {
            tmp = 1;
            r[i] = tmp;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i - 1] + 1 < a[i + 1]) {
            ans = max(ans, l[i - 1] + r[i + 1] + 1);
        } else {
            ans = max(ans, max(l[i - 1] + 1, r[i + 1] + 1));
        }
    }
    printf("%d\n", ans);
    return 0;
}