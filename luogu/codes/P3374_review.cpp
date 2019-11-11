/*************************************************************
 *  > File Name        : P3374_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 08:13:46
 *  > Algorithm        : review BIT
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500010;

int t[maxn], n;
void add(int x, int k) { for (; x <= n; x += x & -x) t[x] += k; }
int ask(int x) { int res = 0; for (; x; x -= x & -x) res += t[x]; return res; }

int main() {
    n = read(); int m = read();
    for (int i = 1; i <= n; ++i) {
        int a = read();
        add(i, a);
    }
    for (int i = 1; i <= m; ++i) {
        int opt = read(), x = read(), y = read();
        if (opt == 1) {
            add(x, y);
        } else if (opt == 2) {
            printf("%d\n", ask(y) - ask(x - 1));
        }
    }
    return 0;
}