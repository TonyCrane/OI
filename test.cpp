#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

int a[maxn], old[maxn];

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read(); old[i] = a[i];
    }
    sort(old + 1, old + 1 + n);
    int len = unique(old + 1, old + 1 + n) - old - 1;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(old + 1, old + 1 + len, a[i]) - old;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d --> %d\n", old[a[i]], a[i]);
    }
    return 0;
}