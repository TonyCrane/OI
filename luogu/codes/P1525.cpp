/*************************************************************
 *  > File Name        : P1525.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 15:52:04
 *  > Algorithm        : UFS
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 20010;

struct Node {
    int x, y, z;
}f[100010];

int n, m, ufs[maxn], b[maxn];

bool cmp(Node a, Node b) {
    return a.z > b.z;
}

int find(int x) {
    if (ufs[x] == x) return x;
    return ufs[x] = find(ufs[x]);
}

void unionn(int x, int y) {
    x = find(ufs[x]);
    y = find(ufs[y]);
    ufs[x] = y;
}

bool check(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    return false;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) ufs[i] = i;
    for (int i = 1; i <= m; ++i) {
        f[i].x = read();
        f[i].y = read();
        f[i].z = read();
    }
    sort(f + 1, f + 1 + m, cmp);
    for (int i = 1; i <= m + 1; ++i) {
        if (check(f[i].x, f[i].y)) {
            printf("%d\n", f[i].z);
            break;
        } else {
            if (!b[f[i].x]) b[f[i].x] = f[i].y;
            else unionn(b[f[i].x], f[i].y);
            if (!b[f[i].y]) b[f[i].y] = f[i].x;
            else unionn(b[f[i].y], f[i].x);
        }
    }
    return 0;
}