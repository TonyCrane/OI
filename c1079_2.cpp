/*************************************************************
 *  > File Name        : c1079_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/25 15:40:29
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

const int maxn = 100010;

int n, m, len, a[maxn];

struct Query {
    int l, r, q, v;
    int id, pos;
};
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) a.pos < b.pos;
    return a.r < a.r;
}

int main() {
    n = read(), m = read(); len = sqrt(n);
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) {
        
    }
    return 0;
}