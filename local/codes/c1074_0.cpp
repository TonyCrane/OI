/*************************************************************
 *  > File Name        : c1074_0.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/12 12:23:10
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

const int maxn = 10010;

int n, L, R, ansl, ansr, ans = 0, maxa = 0;
double S;
bool vis[maxn];

int main() {
    n = read(); scanf("%lf", &S);
    L = read(); R = read();
    for (int i = 1; i < n; ++i) {
        int l = read(), r = read();
        for (int j = l; j <= r; ++j) {
            vis[j] = true;
        }
    }
    int nowl, nowr, now = 0;
    for (int i = L; i <= R; ++i) {
        if (!vis[i]) {
            if (now == 0) nowl = i;
            now++;
        } else {
            now = 0;
        }
        if (now > ans) {
            ans = now;
            ansl = nowl;
            ansr = i;
        }
    }
    if (ans == 0) printf("0 0\n");
    else printf("%d %d\n", ansl, ansr);
    return 0;
}