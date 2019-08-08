/*************************************************************
 *  > File Name        : 1125.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/07 16:04:48
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

const int maxn = 100010;

int n, m, ans;
int d[maxn], h[maxn];

int main() {
    n = read(); m = read();
    for (int i = 1; i <= m; ++i) {
        d[i] = read(), h[i] = read();
        if (i == 1) ans = d[i] + h[i] - 1;
        else {
            int dt = d[i] - d[i - 1];
            int dh = abs(h[i] - h[i - 1]);
            if (dh > dt) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
            ans = max(ans, max(h[i], h[i - 1]));
            int l = 0, r = 0x3f3f3f3f, mid, now = 0;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (mid + abs(mid - dh) <= dt) {
                    now = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(ans, min(h[i], h[i - 1]) + now);
        }
        if (i == m) {
            ans = max(ans, h[i] + n - d[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}