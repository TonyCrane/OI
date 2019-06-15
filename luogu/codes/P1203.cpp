/*************************************************************
 *  > File Name        : P1203.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/15 16:00:09
 *  > Algorithm        : No
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

char a[1010]; int b[10010];

int main() {
    int n = read();
    scanf("%s", a);
    for (int i = n; i < n * 2; ++i) {
        a[i] = a[i - n];
    }
    int maxx = 0;
    for (int i = 0; i < n * 2; ++i) {
        int l = i, r = i + 1;
        char al = a[l], ar = a[r];
        if (a[l] == 'w') al = a[l - 1];
        if (a[r] == 'w') ar = a[r - 1];
        int ans = 0;
        while (l >= 0) {
            if (a[l] == al || a[l] == 'w') ans++;
            else break; l--;
        }
        while (r < n * 2) {
            if (a[r] == ar || a[r] == 'w') ans++;
            else break; r++;
        }
        maxx = max(maxx, ans);
    }
    printf("%d\n", min(maxx, n));
    return 0;
}