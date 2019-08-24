/*************************************************************
 *  > File Name        : T94419.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/24 12:03:02
 *  > Algorithm        : XOR
**************************************************************/


#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, ans, w;

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        w = read();
        ans ^= w;
    }
    printf("%d\n", ans);
    return 0;
}