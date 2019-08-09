/*************************************************************
 *  > File Name        : 1131.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/09 12:13:35
 *  > Algorithm        : 打表
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

int n, tab[10][10], a[10];
char s[35];

int main() {
    tab[2][2] = 1; 
    tab[3][3] = 1; 
    tab[4][2] = 2; tab[4][3] = 1;
    tab[5][5] = 1; 
    tab[6][3] = 1; tab[6][5] = 1;
    tab[7][7] = 1; 
    tab[8][2] = 3; tab[8][7] = 1;
    tab[9][2] = 1; tab[9][3] = 2; tab[9][7] = 1;
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            a[j] += tab[s[i] - 48][j];
        }
    }
    for (int j = 9; j ; j--) {
        while (a[j]) {
            printf("%d", j);
            a[j]--;
        }
    }
    printf("\n");
    return 0;
}