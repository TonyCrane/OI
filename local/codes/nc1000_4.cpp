/*************************************************************
 *  > File Name        : c1000_4.cpp
 *  > Author           : Tony
 *  > Created Time     : 2020/01/15 12:26:37
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

const int maxn = 10010;

int n;

int vis[maxn];
int prime[maxn], sum[maxn], num;
void getprime(int n) {
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= n; ++i) {
        if (vis[i] == 0) {
            vis[i] = i;
            prime[++num] = i;
        }
        for (int j = 1; j <= num; ++j) {
            if (prime[j] > vis[i] || prime[j] > n / i) break;
            vis[i * prime[j]] = prime[j];
        }
    }
}

int main() {
    n = read();
    getprime(1000);
    // for (int i = 1; i <= n; ++i) printf("%d ", prime[i]);
    while (n != 1) {
        for (int i = 1; i <= 1000; ++i) {
            if (n % prime[i] == 0) {
                n = n / prime[i];
                printf("%d ", prime[i]);
                break;
            }
        }
    }
    return 0;
}