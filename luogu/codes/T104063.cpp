/*************************************************************
 *  > File Name        : T104063.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/27 13:45:56
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

const int maxn = 300010;

int n, a[maxn];
double sum[maxn];
double ans = 0.0;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (double)a[i];
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, sum[i] * sum[i] / (double)i);
    }   
    printf("%.9lf\n", ans);
    return 0;
}