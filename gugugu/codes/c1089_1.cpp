/*************************************************************
 *  > File Name        : c1089_1.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 15:20:08
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

const int maxn = 10010;

int n, m, a[maxn], rest, num, b[maxn], cnt;
priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int T = read();
    while (T--) {
        n = read(); m = read();
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        for (int i = 1; i <= n; ++i) {
            rest = m - a[i], num = 1; cnt = 0;
            while (rest > 0 && !q.empty()) {
                if (rest - q.top() < 0) break;
                rest -= q.top(); b[++cnt] = q.top();
                q.pop(); num++;
            }
            q.push(a[i]);
            for (; cnt > 0; --cnt) {
                q.push(b[cnt]);
            }
            printf("%d ", i - num);
        }
        printf("\n");
        while (!q.empty()) q.pop();
    }
    return 0;
}