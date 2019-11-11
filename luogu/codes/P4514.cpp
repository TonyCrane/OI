/*************************************************************
 *  > File Name        : P4514.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 10:53:42
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

const int maxn = 2050;

int n, m;
int t1[maxn][maxn];
int t2[maxn][maxn];
int t3[maxn][maxn];
int t4[maxn][maxn];

void add(int x, int y, int k) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= m; j += j & -j) {
            t1[i][j] += k;
            t2[i][j] += k * x;
            t3[i][j] += k * y;
            t4[i][j] += k * x * y;
        }
    }
}
 
int ask(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i) {
        for (int j = y; j; j -= j & -j) {
            res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        }
    }
    return res;
}

int main() {
    char opt[3]; scanf("%s", opt);
    n = read(); m = read();
    while (~scanf("%s", opt)) {
        int a = read(), b = read(), c = read(), d = read();
        if (opt[0] == 'L') {
            int k = read();
            add(c + 1, d + 1, k);
            add(a, d + 1, -k);
            add(c + 1, b, -k);
            add(a, b, k);
        } else {
            printf("%d\n", ask(c, d) - ask(c, b - 1) - ask(a - 1, d) + ask(a - 1, b - 1));
        }
    }
    return 0;
}