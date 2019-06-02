/*************************************************************
 *  > File Name        : hdu3038.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/02 12:12:38
 *  > Algorithm        : [DataStructure]UFSwithVal
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;

int ans;

struct UnionFindSet {
    int ufs[maxn], rank[maxn];
    void init() {
        memset(rank, 0, sizeof(rank));
        for (int i = 0; i < maxn - 10; ++i) {
            ufs[i] = i;
        }
    }
    int find(int x) {
        if (x == ufs[x]) return x;
        int fx = ufs[x];
        ufs[x] = find(ufs[x]);
        rank[x] += rank[fx];
        return ufs[x];
    }
    void unionn(int a, int b, int s) {
        int x = find(a), y = find(b);
        if (x == y) {
            if (rank[a] + s != rank[b]) ans++;
            return;
        } else {
            ufs[y] = x;
            rank[y] = rank[a] + s - rank[b];
        }
    }
}ufs;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int a, b, s; ans = 0;
        ufs.init();
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d %d", &a, &b, &s);
            ufs.unionn(a, b + 1, s);
        }
        printf("%d\n", ans);
    }
    return 0;
}