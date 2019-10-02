/*************************************************************
 *  > File Name        : P2197.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/02 15:57:39
 *  > Algorithm        : nim
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int main() {
    int T = read();
    while (T--) {
        int n = read(), ans = 0;
        for (int i = 1; i <= n; ++i) {
            int x = read();
            ans ^= x;
        }
        printf(!ans ? "No\n" : "Yes\n");
    }
    return 0;
}