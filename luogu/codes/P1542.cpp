/*************************************************************
 *  > File Name        : P1542.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/11 11:59:12
 *  > Algorithm        : [Dichotomy]Answer
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

int n, x[maxn], y[maxn], s[maxn];
long double l, r, mid;

bool check(long double mid) {
    long double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += s[i] / mid;
        if (sum > y[i]) return false;
        if (sum < x[i]) sum = x[i];
    }
    return true;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        x[i] = read(); y[i] = read(); s[i] = read();
    }
    l = 0, r = 1e9;
    while (r - l >= 0.000001) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    printf("%.2Lf\n", r);
    return 0;
}