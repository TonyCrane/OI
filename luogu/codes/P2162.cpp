/*************************************************************
 *  > File Name        : P2162.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/31 15:26:20
 *  > Algorithm        : [DataStructure]BIT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int tree[maxn], End[maxn], n, ans;
char opt[2];

int lowbit(int k) { return k & -k; }

void add(int x, int k) {
    while (x <= maxn) {
        tree[x] += k;
        x += lowbit(x);
    }
}

int sum(int x) {
    int ans = 0;
    while (x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", opt);
        if (opt[0] == 'A') {
            int del = 0, st, ed;
            scanf("%d %d", &st, &ed);
            for (int j = sum(ed); j; j = sum(ed)) {
                int l = 0, r = ed;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (sum(mid) + 1 <= j) l = mid + 1;
                    else r = mid;
                }
                if (End[l] >= st) {
                    add(l, -1);
                    del++;
                    ans--;
                } else break;
            }
            add(st, 1);
            End[st] = ed;
            ans++;
            printf("%d\n", del);
        } else printf("%d\n", ans);
    }
    return 0;
}