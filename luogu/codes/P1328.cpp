/*************************************************************
 *  > File Name        : P1328.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/21 13:14:14
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;
int n, na, nb, a[maxn], b[maxn], cnta, cntb;
int vs[5][5] = {{0, 0, 1, 1, 0},
                {1, 0, 0, 1, 0},
                {0, 1, 0, 0, 1},
                {0, 0, 1, 0, 1},
                {1, 1, 0, 0, 0}};

int main(){
    scanf("%d %d %d", &n, &na, &nb);
    for (int i = 0; i < na; i++) scanf("%d", &a[i]);
    for (int i = 0; i < nb; i++) scanf("%d", &b[i]);
    for (int i = 0; i < n ; i++) {
        cnta += vs[a[i % na]][b[i % nb]];
        cntb += vs[b[i % nb]][a[i % na]];
    }
    printf("%d %d\n", cnta, cntb);
    return 0;
}