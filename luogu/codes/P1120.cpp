/*************************************************************
 *  > File Name        : P1120.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/06/20 16:13:05
 *  > Algorithm        : [Dfs]Ex
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 500010;

int num[maxn], maxx, minn, sum;

#define max(a, b) a < b ? b : a
#define min(a, b) a > b ? b : a

void dfs(int need, int now, int goal, int can) {
    if (need == 0) {
        printf("%d\n", goal);
        exit(0);
    }
    if (now == goal) {
        dfs(need - 1, 0, goal, maxx);
        return;
    }
    for (int i = can; i >= minn; --i) {
        if (num[i] && i + now <= goal) {
            num[i]--;
            dfs(need, i + now, goal, i);
            num[i]++;
            if (now == 0 || now + i == goal) {
                return;
            }
        }
    }
}

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        int l = read();
        if (l <= 50) {
            sum += l;
            num[l]++;
            minn = min(minn, l);
            maxx = max(maxx, l);
        }
    }
    int limit = sum / 2;
    for (int i = maxx; i <= limit; ++i) {
        if (sum % i == 0) {
            dfs(sum / i, 0, i, maxx);
        }
    }
    printf("%d\n", sum);
    return 0;
}