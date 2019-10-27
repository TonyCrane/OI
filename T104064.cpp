/*************************************************************
 *  > File Name        : T104064.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/27 14:00:50
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

const int maxn = 500010;

int n, m, deg1[maxn], deg2[maxn];
int top1[maxn], top2[maxn], cnt1, cnt2;
vector<int> G[maxn];
priority_queue<int> q2;
priority_queue<int, vector<int>, greater<int> > q1;
int ans1, ans2;


int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        deg1[v]++;
        deg2[v]++;
    }
    for (int i = 1; i <= n; ++i) 
        if (deg1[i] == 0) q1.push(i), q2.push(i);
    while (!q1.empty()) {
        int u = q1.top(); q1.pop();
        top1[++cnt1] = u;
        for (int i = 0; i < G[u].size(); ++i) {
            int& v = G[u][i];
            deg1[v]--;
            if (deg1[v] == 0) {
                q1.push(v);
            }
        }
    }
    while (!q2.empty()) {
        int u = q2.top(); q2.pop();
        top2[++cnt2] = u;
        for (int i = 0; i < G[u].size(); ++i) {
            int& v = G[u][i];
            deg2[v]--;
            if (deg2[v] == 0) {
                q2.push(v);
            }
        }
    }
    int last1 = top1[1]; ans1 = 1;
    for (int i = 2; i <= n; ++i) {
        if (top1[i] > last1) {
            ans1++;
            last1 = top1[i];
        }
    }
    int last2 = top2[1]; ans2 = 1;
    for (int i = 2; i <= n; ++i) {
        if (top2[i] > last2) {
            ans2++;
            last2 = top2[i];
        }
    }
    printf("%d\n%d\n", ans1, ans2);
    return 0;
}