/*************************************************************
 *  > File Name        : c1083_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/03 17:18:11
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

const int maxn = 55;

int n, a[maxn][maxn], sum[maxn][maxn];
long long ans;

int ask(int x, int y, int _x, int _y) {
    return sum[_x][_y] - sum[x - 1][_y] - sum[_x][y - 1] + sum[x - 1][y - 1];
}

const int N = 2600;
const int mod = (1 << 11) - 1;

struct Hash_Map {
    int ver[N], nxt[N], head[mod + 10], cnt, val[N];
    void add(int u, int v) {
        ver[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt;
    }
    int& operator [] (int v) {
        for (int i = head[v & mod]; i; i = nxt[i]) {
            if (ver[i] == v) return val[i];
        }
        add(v & mod, v);
        return val[cnt];
    }
}m1[maxn][maxn], m2[maxn][maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            a[i][j] = read();
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) 
    for (int k = i; k <= n; ++k) for (int l = j; l <= n; ++l) {
        int res1 = ask(i, j, k, l);
        ans += m1[i - 1][j - 1][res1];
        m1[k][l][res1]++;
    }
    for (int i = 1; i <= n; ++i) for (int j = n; j >= 1; --j) 
    for (int k = i; k <= n; ++k) for (int l = j; l >= 1; --l) {
        int res1 = ask(i, l, k, j);
        ans += m2[i - 1][j + 1][res1];
        m2[k][l][res1]++;
    }
    printf("%lld\n", ans);
    return 0;
}