/*************************************************************
 *  > File Name        : 1498.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/27 15:30:07
 *  > Algorithm        : math
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const double PI = 3.141592653589793238;

int a1, b1, a2, b2;

int main() {
    int T = read();
    while (T--) {
        bool flag = false;
        a1 = read(); b1 = read();
        a2 = read(); b2 = read();
        if (a1 > b1) swap(a1, b1);
        if (a2 > b2) swap(a2, b2);
        if (a1 > a2) {
            swap(a1, a2); swap(b1, b2);
        }
        if (b1 <= b2) {
            printf("Yes\n");
            continue;
        }
        for (double theta = 0; theta <= PI / 2; theta += 0.01) {
            if (b1 * sin(theta) + a1 * cos(theta) <= a2 &&\
                a1 * sin(theta) + b1 * cos(theta) <= b2) {
                printf("Yes\n");
                flag = true;
                break;
            }
        }
        if (!flag) printf("No\n");
    }
    return 0;
}