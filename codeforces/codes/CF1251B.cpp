/*************************************************************
 *  > File Name        : CF1251B.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 15:34:27
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

const int maxn = 60;

char str[maxn];
int len, n;

int main() {
    int T = read();
    while (T--) {
        n = read(); int totone = 0, totlen = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", str + 1);
            len = strlen(str + 1);
            totlen += len % 2;
            for (int j = 1; j <= len; ++j) {
                if (str[j] == '1') totone++;
            }
        }
        if (totlen >= totone % 2) printf("%d\n", n);
        else printf("%d\n", n - 1);
    }
    return 0;
}