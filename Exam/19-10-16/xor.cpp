/*************************************************************
 *  > File Name        : xor.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/16 14:53:02
 *  > Algorithm        : 75 Points
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

int n, a[maxn], b[maxn], cnt[maxn], sum[maxn];

namespace Subtask1 {
    void work() {
        sort(b + 1, b + 1 + n);
        int len = unique(b + 1, b + 1 + n) - b - 1;
        for (int i = 1; i <= n; ++i) {
            a[i] = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        }
        int m = read();
        for (int i = 1; i <= m; ++i) {
            int l = read(), r = read(), ans = 0;
            memset(cnt, 0, sizeof(cnt));
            for (int j = l; j <= r; ++j) {
                cnt[a[j]]++;
            }
            for (int j = 1; j <= n; ++j) {
                if (cnt[j] != 0 && cnt[j] % 2 == 0) {
                    ans ^= b[j];
                }
            }
            printf("%d\n", ans);
        }
    }
}

namespace Subtask2 {
    void work() {
        int m = read();
        for (int i = 1; i <= m; ++i) {
            int l = read(), r = read();
            int cnt = sum[r] - sum[l - 1];
            if (cnt % 2 == 0 && cnt != 0) printf("1\n");
            else printf("0\n");
        }
    }
}

int main() {
    n = read(); bool is_sub1 = false;
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i] = read();
        if (!is_sub1 && a[i] > 1) is_sub1 = true;
        if (!is_sub1) sum[i] = sum[i - 1] + a[i];
    }
    if (is_sub1) {
        Subtask1::work();
    } else {
        Subtask2::work();
    }
    return 0;
}