/*************************************************************
 *  > File Name        : P3812.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/04/13 13:42:19
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

const int maxn = 55;

int n;
LL a[maxn], p[maxn];
bool flag = true;

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

LL queryMax() {
    LL ans = 0;
    for (int i = 61; i >= 0; --i) {
        if ((ans ^ p[i]) > ans) {
            ans ^= p[i];
        }
    }
    return ans;
}

LL queryMin() {
    if (!flag) return 0LL;
    for (int i = 0; i <= 61; ++i) {
        if (p[i]) return p[i];
    }
}

LL queryKth(LL k) {
    if (k == 1LL && !flag) return 0;
    if (!flag) k--;
    for (int i = 1; i <= 61; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (p[i] & (1LL << (j - 1))) p[i] ^= p[j - 1];
        }
    }
    LL ans = 0;
    for (int i = 0; i <= 61; ++i) {
        if (p[i] != 0) {
            if (k & 1) ans ^= p[i];
            k /= 2;
        }
    }
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        if (!insert(a[i])) {
            flag = false;
        }
    }
    printf("%lld\n", queryMax());
    return 0;
}
