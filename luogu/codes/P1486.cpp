/*************************************************************
 *  > File Name        : P1486.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/12 15:36:31
 *  > Algorithm        : [DataStructure]fhq_Treap
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 110000;

int ch[maxn][2];
int val[maxn], cnt[maxn], siz[maxn];
int sz;
void update(int p) {
    siz[p] = 1 + siz[ch[p][0]] + siz[ch[p][1]];
}
int New(int Val) {
    siz[++sz] = 1;
    val[sz]   = Val;
    cnt[sz]   = rand();
    return sz;
}
int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (cnt[x] < cnt[y]) {
        ch[x][1] = merge(ch[x][1], y);
        update(x);
        return x;
    } else {
        ch[y][0] = merge(x, ch[y][0]);
        update(y);
        return y;
    }
}
void split(int now, int k, int& x, int& y) {
    if (!now) x = y = 0;
    else {
        if (val[now] <= k) {
            x = now;
            split(ch[now][1], k, ch[now][1], y);
        } else {
            y = now;
            split(ch[now][0], k, x, ch[now][0]);
        }
        update(now);
    }
}
int kth(int now, int k) {
    while (true) {
        if (k <= siz[ch[now][0]]) {
            now = ch[now][0];
        } else if (k == siz[ch[now][0]] + 1) {
            return now;
        } else {
            k -= siz[ch[now][0]] + 1;
            now = ch[now][1];
        }
    }
}

int main() {
    srand((int)time(NULL));
    int n = read(), minn = read();
    int root = 0, x, y, z;
    int delta = 0, leave = 0;
    for (int i = 1; i <= n; ++i) {
        char opt[3]; scanf("%s", opt);
        int k = read();
        if (opt[0] == 'I') {
            if (k >= minn) {
                k -= delta;
                split(root, k, x, y);
                root = merge(x, merge(New(k), y));
            }
        } else if (opt[0] == 'A') {
            delta += k;
        } else if (opt[0] == 'S') {
            delta -= k;
            split(root, minn - delta - 1, x, y);
            root = y;
            leave += siz[x];
        } else if (opt[0] == 'F') {
            if (siz[root] < k) {
                printf("-1\n");
            } else {
                printf("%d\n", val[kth(root, siz[root] - k + 1)] + delta);
            }
        }
    }
    printf("%d\n", leave);
    return 0;
}