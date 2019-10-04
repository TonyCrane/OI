/*************************************************************
 *  > File Name        : P3369_BIT.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/03 12:10:42
 *  > Algorithm        : BinaryIndexedTree
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
const int maxm = 20000010;
const int half = 10000000;

int t[maxm+10];

inline void add(int x, int k) {
    for (; x <= maxm; x += x & -x) t[x] += k;
}
inline int ask(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += t[x];
    return ans;
}
inline int Kth(int x) {
    int res = 1 << 25;
    for (int i = 1 << 25; i; i >>= 1) {
        if (t[res - i] >= x) res -= i;
        else x -= t[res - i];
    }
    return res - half;
}

int main() {
    int n = read();
    while (n--) {
        int opt = read(), x = read() + half;
        if (opt == 1) {
            add(x, 1);
        } else if (opt == 2) {
            add(x, -1);
        } else if (opt == 3) {
            printf("%d\n", ask(x - 1) + 1);
        } else if (opt == 4) {
            printf("%d\n", Kth(x - half));
        } else if (opt == 5) {
            printf("%d\n", Kth(ask(x - 1)));
        } else if (opt == 6) {
            printf("%d\n", Kth(ask(x) + 1));
        }
    }
    return 0;
}