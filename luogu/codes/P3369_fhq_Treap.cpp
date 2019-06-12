/*************************************************************
 *  > File Name        : P3369_fhq_Treap.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/12 15:06:08
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

const int maxn = 500010;
const int inf  = 0x3f3f3f3f;

struct fhq_Treap {
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
    int root = 0, x, y, z;
    void insert(int Val) {
        split(root, Val, x, y);
        root = merge(merge(x, New(Val)), y);
    }
    void Remove(int Val) {
        split(root, Val, x, z);
        split(x, Val - 1, x, y);
        y = merge(ch[y][0], ch[y][1]);
        root = merge(merge(x, y), z);
    }
    void getRank(int Val) {
        split(root, Val - 1, x, y);
        printf("%d\n", siz[x] + 1);
        root = merge(x, y);
    }
    void getVal(int rank) {
        printf("%d\n", val[kth(root, rank)]);
    }
    void getPre(int Val) {
        split(root, Val - 1, x, y);
        printf("%d\n", val[kth(x, siz[x])]);
        root = merge(x, y);
    }
    void getSuf(int Val) {
        split(root, Val, x, y);
        printf("%d\n", val[kth(y, 1)]);
        root = merge(x, y);
    }
} fhq;

int main() {
    srand((int)time(NULL));
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int opt = read(), x = read();
        if      (opt == 1) fhq.insert(x);
        else if (opt == 2) fhq.Remove(x);
        else if (opt == 3) fhq.getRank(x);
        else if (opt == 4) fhq.getVal(x);
        else if (opt == 5) fhq.getPre(x);
        else if (opt == 6) fhq.getSuf(x);
    }
    return 0;
}