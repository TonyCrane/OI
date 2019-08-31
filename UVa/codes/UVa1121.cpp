/*************************************************************
 *  > File Name        : UVa1121.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/30 12:32:06
 *  > Algorithm        : 尺取法
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 100010;
const int inf  = 0x3f3f3f3f;

int a[maxn], sum[maxn];
int n, s;

int main() {
    while (scanf("%d %d", &n, &s) != EOF) {
        int minn = inf;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
            sum[i] = sum[i - 1] + a[i];
        }
        int l = 1, r = 1;
        while (l <= n && r <= n) {
            if (sum[r] - sum[l - 1] < s) {
                r++;
            } else {
                minn = min(minn, r - l + 1);
                l++;
            }
        }
        if (minn == inf) {
            printf("0\n");
        } else {
            printf("%d\n", minn);
        }
    }
    return 0;
}