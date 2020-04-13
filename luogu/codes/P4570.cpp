/*************************************************************
 *  > File Name        : P4570.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/13 14:19:24
 *  > Algorithm        : 线性基
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10LL + ch - 48LL; ch = getchar();}
    return x * f;
}

const int maxn = 1010;

int n;
struct Stone {
    LL number, magic;
} a[maxn];
bool cmp(Stone a, Stone b) {
    return a.magic > b.magic;
}
LL p[64];

bool insert(LL x) {
    for (int i = 61; i >= 0; --i) {
        if (x & (1LL << i)) {
            if (p[i]) x ^= p[i];
            else {
                p[i] = x;
                return true;
            }
        }
    }
    return false;
}

LL ans = 0;

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i].number = read();
        a[i].magic = read();
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        if (insert(a[i].number)) {
            ans += a[i].magic;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
