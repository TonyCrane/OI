/*************************************************************
 *  > File Name        : P3367_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 07:54:14
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

const int maxn = 10010;

int ufs[maxn];
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    for (int i = 1; i <= m; ++i) {
        int opt = read(), u = read(), v = read();
        if (opt == 1) {
            int fx = find(u), fy = find(v);
            if (fx != fy) {
                ufs[fx] = fy;
            }
        } else {
            int fx = find(u), fy = find(v);
            if (fx == fy) puts("Y");
            else puts("N");
        }
    }
    return 0;
}