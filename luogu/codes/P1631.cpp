/*************************************************************
 *  > File Name        : P1631.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/17 15:20:15
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

struct Node {
    int val, id, nxt;
    Node(int v, int i, int n): val(v), id(i), nxt(n) {}
};

bool operator < (const Node& a, const Node& b) {
    return a.val > b.val;
}

int n, a[maxn], b[maxn];
priority_queue<Node> q;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    for (int i = 0; i < n; ++i) {
        q.push(Node( a[i] + b[0], i, 1 ));
    }
    for (int i = 0; i < n; ++i) {
        Node t = q.top(); q.pop();
        printf("%d ", t.val);
        q.push(Node( a[t.id] + b[t.nxt], t.id, t.nxt + 1 ));
    }
    return 0;
}