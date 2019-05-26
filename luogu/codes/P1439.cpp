/*************************************************************
 *  > File Name        : P1439.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 11:34:50
 *  > Algorithm        : DP-LCS
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

int f[maxn], a[maxn], b[maxn], _map[maxn], len;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) a[i] = read(), _map[a[i]] = i;
    for (int i = 1; i <= n; ++i) b[i] = read(), f[i] = 0x7f7f7f7f;
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int l = 0, r = len, mid;
        if (_map[b[i]] > f[len]) {
            f[++len] = _map[b[i]];
        } else {
            while (l < r) {
                mid = (l + r) >> 1;
                if (f[mid] > _map[b[i]]) r = mid;
                else l = mid + 1;
            }
            f[l] = min(_map[b[i]], f[l]);
        }
    }
    printf("%d\n", len);
    return 0;
}