/*************************************************************
 *  > File Name        : P3391.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/12 16:00:42
 *  > Algorithm        : [DataStructure]Splay
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

struct Node {
    int ch[2];
    int fa, v, size, mark;
    void init(int x, int f) {
        fa = ch[0] = ch[1] = 0;
        size = 1; v = x; fa = f;
    }
} a[maxn];
int n, m, root, tot;
void pushup(int x) {
    a[x].size = a[a[x].ch[0]].size + a[a[x].ch[1]].size + 1;
} 
void pushdown(int x) {
    if (a[x].mark) {
        a[a[x].ch[0]].mark ^= 1;
        a[a[x].ch[1]].mark ^= 1;
        a[x].mark = 0;
        swap(a[x].ch[0], a[x].ch[1]);
    }
}
void rotate(int x) {
    int y = a[x].fa;
    int z = a[y].fa;
    int k = a[y].ch[1] == x;
    a[z].ch[a[z].ch[1] == y] = x;
    a[x].fa = z;
    a[y].ch[k] = a[x].ch[k ^ 1];
    a[a[x].ch[k ^ 1]].fa = y;
    a[x].ch[k ^ 1] = y;
    a[y].fa = x;
    pushup(y); pushup(x);
}
void Splay(int x, int goal) {
    while(a[x].fa != goal) {
        int y = a[x].fa;
        int z = a[y].fa;
        if (z!=goal) (a[z].ch[1] == y) ^ (a[y].ch[1] == x) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (goal == 0) root = x;
}
void insert(int x) {
    int u = root, fa = 0;
    while (u) fa = u, u = a[u].ch[x > a[u].v];
    u = ++tot;
    if (fa) a[fa].ch[x > a[fa].v] = u;
    a[u].init(x, fa);
    Splay(u, 0);
}
int Kth(int k) {
    int u = root;
    while (true) {
        pushdown(u);
        if (a[a[u].ch[0]].size >= k) u = a[u].ch[0];
        else if (a[a[u].ch[0]].size + 1 == k) return u;
        else k -= a[a[u].ch[0]].size + 1, u = a[u].ch[1];
    }
}
void write(int u) {
    pushdown(u);
    if (a[u].ch[0]) write(a[u].ch[0]);
    if (a[u].v > 1 && a[u].v < n + 2) printf("%d ", a[u].v - 1);
    if (a[u].ch[1]) write(a[u].ch[1]);
}
void Work(int l, int r) {
    l = Kth(l);
    r = Kth(r + 2);
    Splay(l, 0);
    Splay(r, l);
    a[a[a[root].ch[1]].ch[0]].mark ^= 1;
}

int main() {
    n = read(); m = read();
    for(int i = 1; i <= n + 2; ++i) insert(i);
    while (m--) {
        int l = read(), r = read();
        Work(l, r);
    }
    write(root);
    printf("\n");
    return 0;
}