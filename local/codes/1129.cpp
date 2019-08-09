/*************************************************************
 *  > File Name        : 1129.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/08 17:41:41
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

const int maxn = 50010;

int n;
int p[maxn], q[maxn], p2[maxn], q2[maxn];
int cnt[maxn], ans[maxn];

int main() {
    n = read();
    for (int i = n; i >= 1; i--) p[i] = read();
    for (int i = n; i >= 1; i--) q[i] = read();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (p[j] < p[i]) p2[i]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (q[j] < q[i]) q2[i]++;
        }
    }
    for (int i = 2; i <= n; ++i) {
        ans[i] += p2[i] + q2[i];
        ans[i + 1] += ans[i] / i;
        ans[i] %= i;
    }
    for (int i = n; i >= 1; --i) {
        int tmp = -1;
        while (ans[i] >= 0) {
            tmp++;
            if (!cnt[tmp]) ans[i]--;
        }
        printf("%d ", tmp);
        cnt[tmp] = 1;
    }
    return 0;
}