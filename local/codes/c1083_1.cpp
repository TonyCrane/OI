/*************************************************************
 *  > File Name        : c1083_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/01 16:08:22
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

const int maxn = 300010;

int n, k, c[maxn];
long long ans;

struct Node {
    int m, v;
    Node() {}
    Node(int m, int v): m(m), v(v) {}
    bool operator < (const Node& a) const {
        if (v == a.v) return m < a.m;
        return v > a.v;
    }
}book[maxn];
multiset<int> s;

int main() {
    n = read(); k = read();
    for (int i = 1; i <= n; ++i) {
        book[i].m = read();
        book[i].v = read();
    }
    sort(book + 1, book + 1 + n);
    for (int i = 1; i <= k; ++i) c[i] = read(), s.insert(c[i]);
    for (int i = 1; i <= n; ++i) {
        multiset<int>::iterator pos = s.lower_bound(book[i].m);
        if (pos == s.end()) continue;
        ans += (long long)book[i].v;
        s.erase(pos);
    }
    printf("%lld\n", ans);
    return 0;
}