/*************************************************************
 *  > File Name        : P1196_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 09:29:33
 *  > Algorithm        : review ufs
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

int ufs[maxn], d[maxn], siz[maxn];

int find(int x) {
    if (ufs[x] == x) return x;
    int root = find(ufs[x]);
    d[x] += d[ufs[x]];
    return ufs[x] = root;
}

void unionn(int x, int y) {
    x = find(x); y = find(y);
    ufs[x] = y; d[x] = siz[y];
    siz[y] += siz[x];
}

int main() {
    for (int i = 1; i <= 30000; ++i) {
        ufs[i] = i;
        siz[i] = 1;
    }
    int T = read();
    while (T--) {
        char opt[3]; scanf("%s", opt);
        int x = read(), y = read();
        if (opt[0] == 'M') {
            unionn(x, y);
        } else {
            int fx = find(x), fy = find(y);
            if (fx != fy) puts("-1");
            else printf("%d\n", abs(d[x] - d[y]) - 1);
        }
    }
    return 0;
}