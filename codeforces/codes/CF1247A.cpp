/*************************************************************
 *  > File Name        : CF1247A.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 19:15:54
 *  > Algorithm        : +
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int da, db;

int main() {
    da = read(); db = read();
    if (da == 9 && db == 1) {
        printf("9 10\n");
    } else if (da > db || db - da >= 2) {
        printf("-1\n");
    } else if (da == db) {
        printf("%d %d\n", da * 10 + 2, db * 10 + 3);
    } else if (db - da == 1) {
        printf("%d %d\n", da * 10 + 9 , db * 10);
    }
    return 0;
}