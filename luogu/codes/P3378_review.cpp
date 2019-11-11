/*************************************************************
 *  > File Name        : P3378_review.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/11 07:59:24
 *  > Algorithm        : review heap
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

priority_queue<int, vector<int>, greater<int> > q; 

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int opt = read();
        if (opt == 1) {
            int x = read();
            q.push(x);
        } else if (opt == 2) {
            printf("%d\n", q.top());
        } else {
            q.pop();
        }
    }
    return 0;
}