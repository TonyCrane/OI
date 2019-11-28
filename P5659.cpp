/*************************************************************
 *  > File Name        : P5659.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/28 16:07:38
 *  > Algorithm        : tree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2010;

int n;
vector<int> G[maxn];

namespace Subtask1 {
    int id[maxn], Val[maxn], del[maxn], val[maxn], ans[maxn];
    struct Edge {
        int u, v;
    }edges[maxn];
    bool better() {
        for (int i = 1; i <= n; ++i) {
            if (ans[i] != val[i]) {
                return val[i] < ans[i];
            }
        }
        return false;
    }
    void work() {
        memset(ans, 0, sizeof(ans));
        memset(edges, 0, sizeof(edges));
        memset(Val, 0, sizeof(Val));
        for (int i = 1; i <= n; ++i) {
            int id = read();
            Val[id] = i;
        }
        for (int i = 1; i < n; ++i) {
            int u = read(), v = read();
            edges[i].u = u;
            edges[i].v = v;
        }
        for (int i = 1; i < n; ++i) {
            del[i] = i;
        }
        do {
            for (int i = 1; i <= n; ++i) {
                val[i] = Val[i];
            }
            for (int i = 1; i < n; ++i) {
                swap(val[edges[del[i]].u], val[edges[del[i]].v]);
            }
            if (ans[1] == 0) {
                memcpy(ans, val, sizeof(ans));
            }
            if (better()) {
                memcpy(ans, val, sizeof(ans));
            }
            for (int i = 1; i <= n; ++i) {
                printf("%d ", val[i]);
            }
            puts("");
        } while (next_permutation(del + 1, del + n));
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ans[i]);
        }
        puts("");
        return;
    }
}

int main() {
    int T = read();
    while (T--) {
        n = read();
        if (n <= 10) Subtask1::work();
    }
    return 0;
}