/*************************************************************
 *  > File Name        : P2672.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 15:03:05
 *  > Algorithm        : 贪心
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;

struct Node {
    int s, a;
} node[maxn];

bool cmp(Node a, Node b) {
    return a.a > b.a;
}

int n, sum[maxn], maxs[maxn], max2spa[maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) node[i].s = read();
    for (int i = 1; i <= n; ++i) node[i].a = read();
    sort(node + 1, node + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + node[i].a;
    for (int i = 1; i <= n; ++i) maxs[i] = max(maxs[i - 1], node[i].s);
    for (int i = n; i >= 1; --i) max2spa[i] = max(max2spa[i + 1], node[i].s * 2 + node[i].a);
    for (int i = 1; i <= n; ++i) printf("%d\n", max(sum[i] + 2 * maxs[i], sum[i - 1] + max2spa[i]));
    return 0;
}