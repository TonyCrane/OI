/*************************************************************
 *  > File Name        : P1637.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/26 16:20:04
 *  > Algorithm        : [DataStructure]BIT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 30010;

int n, m, a[maxn];
int tree1[maxn], tree2[maxn];
int A[maxn];
int cntl[maxn], cntr[maxn];

void add1(int x, int k) {
    for (; x <= n; x += x & -x) tree1[x] += k;
}
void add2(int x, int k) {
    for (; x <= n; x += x & -x) tree2[x] += k;
}

int ask1(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += tree1[x];
    return ans;
}
int ask2(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += tree2[x];
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        A[i] = a[i] = read();
    }
    sort(A + 1, A + 1 + n);
    m = unique(A + 1, A + 1 + n) - (A + 1);

    for (int i = 1; i <= n; ++i) {
        add1(lower_bound(A + 1, A + 1 + n, a[i]) - A, 1);
        cntl[i] = ask1((lower_bound(A + 1, A + 1 + n, a[i]) - A) - 1);
    }
    for (int i = n; i >= 1; --i) {
        add2(lower_bound(A + 1, A + 1 + n, a[i]) - A, 1);
        cntr[i] = n - i - ask2((lower_bound(A + 1, A + 1 + n, a[i]) - A)) + 1;
    }
    long long ans = 0;
    for (int i = 2; i < n; ++i) {
        ans += cntl[i] * cntr[i];
    }
    printf("%lld\n", ans);
    return 0;
}