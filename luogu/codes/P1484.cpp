/*************************************************************
 *  > File Name        : P1484.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/14 15:18:38
 *  > Algorithm        : priority_queue+链表
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500010;

struct Node {
    LL val; int id;
    bool operator < (Node a) const {
        return val < a.val;
    }
};

LL a[maxn], ans;
int l[maxn], r[maxn];
bool valid[maxn];
priority_queue<Node> q;

int main() {
    int n = read(), k = read();
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        q.push((Node){a[i], i});
        l[i] = i - 1;  
        r[i] = i + 1;
    }
    int len = n;
    for (int i = 1; i <= k; ++i) {
        while (!q.empty() && valid[q.top().id]) {
            q.pop();
        }
        if (q.empty() || q.top().val < 0) {
            break;
        }
        Node top = q.top(); q.pop(); ans += top.val;
        valid[top.id] = true;
        valid[l[top.id]] = true;
        valid[r[top.id]] = true;
        a[++len] = a[l[top.id]] + a[r[top.id]] - a[top.id];
        l[len] = l[l[top.id]];
        r[len] = r[r[top.id]];
        r[l[len]] = len;
        l[r[len]] = len;
        q.push((Node){a[len], len});
    }
    printf("%lld\n", ans);
    return 0;
}