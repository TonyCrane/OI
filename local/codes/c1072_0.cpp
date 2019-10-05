/*************************************************************
 *  > File Name        : c1072_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/05 12:25:30
 *  > Algorithm        : math
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

struct Node {
    double p, h;
}a[maxn];
bool cmp(Node a, Node b) {
    return a.p - a.h < b.p - b.h;
}

int main() {
    int n = read(); double ans = 0;
    for (int i = 1; i <= n; ++i) { 
        scanf("%lf %lf", &a[i].p, &a[i].h);
        if (a[i].p < a[i].h) {
            puts("-1");
            return 0;
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    double l = a[1].p - a[1].h;
    double r = a[1].p + a[1].h;
    for (int i = 2; i <= n; ++i) {
        if (a[i].p - a[i].h >= r) {
            l = a[i].p - a[i].h;
            r = a[i].p + a[i].h;
            ans = max(ans, a[i].h);
        } else {
            r = max(r, a[i].p + a[i].h);
            ans = max(ans, (r - l) / 2.0);
        }
    }
    printf("%.1lf\n", ans);
    return 0;
}