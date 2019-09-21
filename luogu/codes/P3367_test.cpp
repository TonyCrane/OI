/*************************************************************
 *  > File Name        : P3367_test.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/21 17:57:40
 *  > Algorithm        : ufs
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

int ufs[maxn];
int n, m;

namespace Test1 {
    int find(int x) {
        return ufs[x] == x ? x : find(ufs[x]);
    }
    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            ufs[fx] = fy;
        }
    }
}

namespace Test2 {
    int find(int x) {
        return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
    }
    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            ufs[fx] = fy;
        }
    }
}

namespace Test3 {
    int dep[maxn];
    int find(int x) {
        return ufs[x] == x ? x : ufs[x] = find(ufs[x]);
    }
    void merge(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (dep[fx] <= dep[fy]) {
            ufs[fx] = fy;
            if (dep[fx] == dep[fy]) {
                dep[fy]++;
            }
        } else {
            ufs[fy] = fx;
        }
    }
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) {
        ufs[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int opt = read(), x = read(), y = read();
        if (opt == 1) {
            Test1::merge(x, y);
        } else {
            if (Test1::find(x) == Test1::find(y)) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
    }
    return 0;
}