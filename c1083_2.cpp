/*************************************************************
 *  > File Name        : c1083_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/03 17:18:11
 *  > Algorithm        : 
**************************************************************/

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 55;

int n, a[maxn][maxn], sum[maxn][maxn];
long long ans;
hash_map<int, int> m1[maxn][maxn];
hash_map<int, int> m2[maxn][maxn];

int ask(int x, int y, int _x, int _y) {
    return sum[_x][_y] - sum[x - 1][_y] - sum[_x][y - 1] + sum[x - 1][y - 1];
}

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