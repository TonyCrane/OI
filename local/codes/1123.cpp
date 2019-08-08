/*************************************************************
 *  > File Name        : 1123.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/07 12:37:07
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

const int maxn = 5050;
int n, x[maxn], ans, pos[maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        x[i] = read();
    }
    sort(x + 1, x + 1 + n);
    pos[++ans] = 1;
    for (int i = 2; i <= n; ++i) {
        int where = 0, maxx = 0;
        for (int j = 1; j <= ans; ++j) {
            if (x[i] >= pos[j] && pos[j] > maxx) {
                maxx = pos[j];
                where = j;
            }
        }
        if (!where) {
            pos[++ans] = 1;
        } else {
            pos[where]++;
        }
    }
    printf("%d\n", ans);
    return 0;
}