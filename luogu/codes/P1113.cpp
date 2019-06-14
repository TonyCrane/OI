/*************************************************************
 *  > File Name        : P1113.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/14 15:20:19
 *  > Algorithm        : [Greedy]
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int ans[10010], Ans;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        i = read(); int l = read();
        int tmp = 0, t;
        while (scanf("%d", &t) && t) {
            tmp = max(ans[t], tmp);
        }
        ans[i] = tmp + l;
        Ans = max(ans[i], Ans);
    }
    printf("%d\n", Ans);
    return 0;
}