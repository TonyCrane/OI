/*************************************************************
 *  > File Name        : P1062.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/20 12:50:52
 *  > Algorithm        : [Math]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

stack<int> s;

int main() {
    LL k = read(), n = read(), ans = 0;
    while (n) {
        s.push(n & 1);
        n >>= 1;
    }
    while (!s.empty()) {
        int t = s.top(); s.pop();
        ans += t * pow(k, s.size());
    }
    printf("%lld\n", ans);
    return 0;
}