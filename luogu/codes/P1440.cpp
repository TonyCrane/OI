/*************************************************************
 *  > File Name        : P1440.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/01 16:33:57
 *  > Algorithm        : [DataStructure]dueue
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 2000010;
struct Node {
    int val, id;
}a[maxn];
deque<Node> q;
int n, m, ans[maxn];

int main() {
    n = read(); m = read();
    for (int i = 0; i < n; ++i) a[i].val = read(), a[i].id = i;
    ans[0] = 0;
    for (int i = 1; i < n; ++i) {
        while (!q.empty() && q.back().val >= a[i - 1].val) q.pop_back(); q.push_back(a[i - 1]);
        while (!q.empty() && q.front().id < i - m) q.pop_front(); ans[i] = q.front().val;
    }
    for (int i = 0; i < n; ++i) printf("%d\n", ans[i]);
    return 0;
}