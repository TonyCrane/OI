/*************************************************************
 *  > File Name        : P3377.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/02 10:51:41
 *  > Algorithm        : [DateStructure]LeftistTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 150010;

int n, m;

struct LeftistTreeNode {
    int dis, val, rt;
    int ls, rs;
    #define ls(x)  tree[x].ls
    #define rs(x)  tree[x].rs
    #define dis(x) tree[x].dis
    #define val(x) tree[x].val
    #define rt(x)  tree[x].rt
}tree[maxn];

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (val(x) > val(y) || (val(x) == val(y) && x > y)) {
        swap(x, y);
    }
    rs(x) = merge(rs(x), y);
    if (dis(ls(x)) < dis(rs(x))) swap(ls(x), rs(x));
    rt(ls(x)) = rt(rs(x)) = rt(x) = x;
    dis(x) = dis(rs(x)) + 1;
    return x;
}

int get(int x) {
    return rt(x) == x ? x : rt(x) = get(rt(x));
}

void pop(int x) {
    val(x) = -1;
    rt(ls(x)) = ls(x); rt(rs(x)) = rs(x);
    rt(x) = merge(ls(x), rs(x));
}

int main() {
    n = read(); m = read(); dis(0) = -1;
    for (int i = 1; i <= n; ++i) {
        rt(i) = i;
        val(i) = read();
    }
    for (int i = 1; i <= m; ++i) {
        int opt = read(), x = read();
        if (opt == 1) {
            int y = read();
            if (val(x) == -1 || val(y) == -1) continue;
            int fx = get(x), fy = get(y);
            if (fx != fy) {
                rt(fx) = rt(fy) = merge(fx, fy);
            }
        } else {
            if (val(x) == -1) puts("-1");
            else printf("%d\n", val(get(x))), pop(get(x));
        }
    }
    return 0;
}