/*************************************************************
 *  > File Name        : c1082_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/31 15:19:46
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

int n, m, ans;
bool flgn, flgm;

int main() {
    n = read() - 1; m = read() - 1;
    if (n > m) swap(n, m);
    if (n <= 1 && m % 3 != 0) {
        printf("impossible\n");
        return 0;
    }
    if (n >= 3) flgn = true;
    if (m >= 3) flgm = true;
    ans += (n / 3) * 2;
    ans += (m / 3) * 2;
    n %= 3; m %= 3;
    if (m && !flgn) ans += 2;
    if (n && !flgm) ans += 2;
    printf("%d\n", ans + n + m);
    return 0;
}