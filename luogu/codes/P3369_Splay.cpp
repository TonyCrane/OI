/*************************************************************
 *  > File Name        : P3369_Splay.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/09 16:01:44
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

const int maxn = 500010;
const int inf  = 0x7f7f7f7f;

int root = 0, n, tot = 0;

struct Node {
    int ch[2], fa;
    int cnt, val, size;
} a[maxn];

void update(int p) {
    a[p].size = a[a[p].ch[0]].size + a[a[p].ch[1]].size + a[p].cnt;
}

void rotate(int p) {
    int y = a[p].fa, z = a[y].fa, k = a[y].ch[1] == p;
    a[z].ch[a[z].ch[1] == y] = p;  a[p].fa = z;
    a[y].ch[k] = a[p].ch[k ^ 1];   a[a[p].ch[k ^ 1]].fa = y;
    a[p].ch[k ^ 1] = y;            a[y].fa = p;
    update(y); update(p);
}

void Splay(int p, int goal) {
    while (a[p].fa != goal) {
        int y = a[p].fa;
        int z = a[y].fa;
        if (z != goal) {
            (a[y].ch[0] == p) ^ (a[z].ch[0] == y) ? rotate(p) : rotate(y);
        }
        rotate(p);
    }
    if (goal == 0) root = p;
}

void insert(int val) {
    int u = root, fa = 0;
    while (u && a[u].val != val) {
        fa = u;
        u = a[u].ch[val > a[u].val];
    }
    if (u) a[u].cnt++;
    else {
        u = ++tot;
        if (fa) a[fa].ch[val > a[fa].val] = u;
        a[tot].ch[0] = 0;
        a[tot].ch[1] = 0;
        a[tot].fa = fa; a[tot].val = val;
        a[tot].cnt = 1; a[tot].size = 1;
    }
    Splay(u, 0);
}

void find(int val) {
    int u = root;
    if (!u) return;
    while (a[u].ch[val > a[u].val] && val != a[u].val) {
        u = a[u].ch[val > a[u].val];
    }
    Splay(u, 0);
}

int Get(int val, int opt) {
    find(val);
    int u = root;
    if ((a[u].val > val && opt) || (a[u].val < val && !opt)) return u;
    u = a[u].ch[opt];
    while (a[u].ch[opt ^ 1]) u = a[u].ch[opt ^ 1];
    return u;
}

void Remove(int val) {
    int last = Get(val, 0);
    int next = Get(val, 1);
    Splay(last, 0); Splay(next, last);
    int del = a[next].ch[0];
    if (a[del].cnt > 1) {
        a[del].cnt--; 
        Splay(del, 0);
    } else a[next].ch[0] = 0; 
}

int K_th(int rank) {
    int u = root;
    if (a[u].size < rank) return false;
    while (true) {
        int y = a[u].ch[0];
        if (rank > a[y].size + a[u].cnt) {
            rank -= a[y].size + a[u].cnt;
            u = a[u].ch[1];
        } else if (a[y].size >= rank) u = y;
        else return a[u].val;
    }
}

int main() {
    insert(-inf); insert(inf);
    n = read();
    while (n--) {
        int opt = read();
        if      (opt == 1) insert(read());
        else if (opt == 2) Remove(read());
        else if (opt == 3) find(read()), printf("%d\n", a[a[root].ch[0]].size);
        else if (opt == 4) printf("%d\n", K_th(read() + 1));
        else if (opt == 5) printf("%d\n", a[Get(read(), 0)].val);
        else if (opt == 6) printf("%d\n", a[Get(read(), 1)].val);
    }
    return 0;
}