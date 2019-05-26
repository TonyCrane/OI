/*************************************************************
 *  > File Name        : P2866.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/26 16:18:52
 *  > Algorithm        : [数据结构]单调栈
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

stack<int> s;
long long ans = 0;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int a = read();
        while (!s.empty() && s.top() <= a) s.pop();
        ans += s.size();
        s.push(a);
    }
    printf("%lld\n", ans);
}