/*************************************************************
 *  > File Name        : c1087_1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/08 16:14:03
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

const int maxn = 100010;

int n, m, K, v[10], a[maxn][10], b[maxn][10];

struct Node {
    int id, a;
    Node(){}
    Node(int id, int a): id(id), a(a) {}
    bool operator < (const Node& b) const {
        return a > b.a;
    }
};
priority_queue<Node> q[maxn];
multiset<int> s;

int main() {
    int T = read();
    while (T--) {
        n = read(); K = read(); m = 0; s.clear();
        for (int i = 1; i <= K; ++i) v[i] = read();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= K; ++j) {
                a[i][j] = read();
                q[j].push(Node(i, a[i][j]));
            }
            for (int j = 1; j <= K; ++j) b[i][j] = read();
        }
        for (int cnt = 1; cnt <= n; ++cnt) {
            for (int i = 1; i <= K; ++i) {
                while (!q[i].empty()) {
                    Node top = q[i].top();
                    if (top.a <= v[i]) {
                        s.insert(top.id);
                        if (s.count(top.id) == K) {
                            s.erase(top.id); m++;
                            for (int j = 1; j <= K; ++j) {
                                v[j] += b[top.id][j];
                            }
                        }
                        q[i].pop();
                    } else break;
                }
            }
        }
        printf("%d\n", m);
        for (int i = 1; i <= K; ++i) {
            printf("%d ", v[i]);
        }
        puts("");
        for (int i = 1; i <= K; ++i) {
            while (!q[i].empty()) q[i].pop();
        }
    }
    return 0;
}