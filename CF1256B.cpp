/*************************************************************
 *  > File Name        : CF1256B.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/04 21:44:49
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

const int maxn = 110;

int a[maxn];

int main() {
    int T = read();
    while (T--) {
        int n = read();
        for (int i = 1; i <= n; ++i) a[i] = read();
        
    }
}