/*************************************************************
 *  > File Name        : c1070_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/09/28 15:59:09
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

const int maxn = 3000010;

int k, n, a[maxn], ans, now;
int q1[maxn], num1[maxn], l1, r1;
int q2[maxn], num2[maxn], l2, r2;


int main() {
    k = read(); n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    for (int i = 1; i <= n; ++i) {
        while (abs(q1[l1] - a[i]) > k && l1 <= r1) now = num1[l1++];
        while (a[i] <= q1[r1] && l1 <= r1) r1--;
        num1[++r1] = i; q1[r1] = a[i];
        while (num1[l1] < now && l1 <= r1) l1++;
        while (num2[l2] < now && l2 <= r2) l2++;
        while (abs(q2[l2] - a[i]) > k && l2 <= r2) now = num2[l2++];
        while (a[i] >= q2[r2] && l2 <= r2) r2--;
        num2[++r2] = i; q2[r2] = a[i];
        while (num1[l1] < now && l1 <= r1) l1++;
        while (num2[l2] < now && l2 <= r2) l2++;
        ans = max(ans, abs(i - now));
    }
    printf("%d\n", ans);
    return 0;
}