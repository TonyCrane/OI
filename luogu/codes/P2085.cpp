/*************************************************************
 *  > File Name        : P2085.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/28 15:34:39
 *  > Algorithm        : priority_queue
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 10010;

int n, m;
int a[maxn], b[maxn], c[maxn], x[maxn];

inline int f(int i) {
    return a[i] * x[i] * x[i] + b[i] * x[i] + c[i];
}

struct heap {
    int f, x;
    bool operator < (const heap& a) const {
        return f > a.f;
    }
};
priority_queue<heap> q;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read(); b[i] = read(); c[i] = read();
        x[i] = 1;
        q.push((heap){f(i), i});
    }
    for (int i = 1; i <= m; ++i) {
        heap top = q.top(); q.pop();
        x[top.x]++;
        printf("%d ", top.f);
        q.push((heap){f(top.x), top.x});
    }
    return 0;
}