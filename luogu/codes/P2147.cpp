/*************************************************************
 *  > File Name        : P2147.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/02 11:39:08
 *  > Algorithm        : [DataStructure]UFSwithDel
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

int n, m;

struct UnionFindSet {
    int ufs[maxn];
    inline void sroot(int u) {
        for (int i = 0, fa = ufs[u]; u; fa = ufs[u]) {
            ufs[u] = i; i = u; u = fa;
        }
    }
    void connect(int u, int v) {
        ufs[u] = v;
    }
    void del(int u, int v) {
        ufs[v] = 0;
    }
    void query(int u, int v) {
        for (; v != u && v; v = ufs[v]);
        puts(v == u ? "Yes" : "No");
    }
}ufs;

int main() {
    n = read(); m = read();
    char opt[10];
    while (m--) {
        int u, v;
        scanf("%s %d %d", opt, &u, &v);
        ufs.sroot(u);
        if      (opt[0] == 'C') ufs.connect(u, v);
        else if (opt[0] == 'D') ufs.del(u, v);
        else if (opt[0] == 'Q') ufs.query(u, v);
    }
    return 0;
}