#include <bits/stdc++.h>
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0; char ch = nc();
    while(ch < '0' || ch > '9') ch = nc();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = nc();
    return x;
}
typedef long long ll;
void print(__int128 x) {
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
const int N = 4e7+10;
const int M = 1e5+10;
int n, type, x, y, z, b[N], m, P[M], l[M], r[M], g[N];
int q[N], head, tail;
ll a[N], p[N];
__int128 ans;
const int mod = 1<<30;
int main() {
    n = read(); type = read();
    if(type == 0) {
        for(int i = 1; i <= n; i++) a[i] = read();
    } else {
        x = read(); y = read(); z = read(); b[1] = read(); b[2] = read(); m = read();
        for(int i = 3; i <= n; i++) b[i] = (1ll * x * b[i-1] + 1ll * y * b[i-2] + z) % mod;
        for(int i = 1; i <= m; i++) {
            P[i] = read(); l[i] = read(); r[i] = read();
        }
        for(int i = 1, j = 1; i <= n; i++) {
            while(i > P[j]) j++;
            a[i] = b[i] % (r[j] - l[j] + 1) + l[j];
        }
    }
    for(int i = 1; i <= n; i++) a[i] += a[i-1];
    for(int i = 1; i <= n; i++) {
        while(head < tail && a[i] - a[q[head+1]] >= p[q[head+1]]) head++;
        int j = q[head];
        p[i] = a[i] - a[j];
        g[i] = j;
        while(head < tail && -p[q[tail]] + p[i] <=  a[q[tail]] - a[i]) tail--;
        q[++tail] = i;
    }
    for(int i = n; i; i = g[i]) ans = ans + (__int128)p[i] * p[i];
    print(ans);
    return 0;
}