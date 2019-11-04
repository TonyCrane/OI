/*************************************************************
 *  > File Name        : CF1256A.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/04 21:14:35
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

int main() {
    int T = read();
    while (T--) {
        long long a = read(), b = read(), n = read(), S = read();
        if (S % n > b || S > a * n + b) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}