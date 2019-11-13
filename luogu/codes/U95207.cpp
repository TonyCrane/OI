/*************************************************************
 *  > File Name        : U95207.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/13 14:00:21
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

const int maxn = 100010;

char str[maxn];
int now, sum, ans = -0x3f3f3f3f;

int main() {
    scanf("%s", str + 1); int n = strlen(str + 1);
    if (n <= 1000) {
        for (int i = 1; i <= n; ++i) {
            int j = i, tmp = 0;
            while (j <= n) {
                if (str[j] == '0') tmp++;
                else tmp--;
                ans = max(ans, tmp);
                j++;
            }
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (str[i] == '0' && str[i - 1] == '1') {
                now = max(0, now - sum) + 1;
                sum = 0;
            } else if (str[i] == '0') {
                now++;
            }
            if (str[i] == '1') {
                sum++;
            }
            ans = max(ans, now);
        }
    }
    printf("%d\n", ans);
    return 0;
}