/*************************************************************
 *  > File Name        : UVa11212.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/08/25 21:20:38
 *  > Algorithm        : IDA*
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 15;

bool fini;
int n, kase, ans;
int a[maxn];

inline int f() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i - 1] + 1) {
            res++;
        }
    }
    return res;
}

void dfs(int dep, int maxd) {
    if (f() + dep * 3 > maxd * 3) return;
    if (!f()) {
        fini = true;
        return;
    }
    int copy1[maxn], copy2[maxn];
    for (int i = 1; i <= n; ++i) {
        copy1[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) { 
        if (a[i] != a[i - 1] + 1) {
            for (int j = i; j <= n; ++j) {
                if (j < n && a[j + 1] == a[j] + 1) continue;
                for (int k = i; k <= j; ++k) {
                    copy2[k] = a[k];
                }
                for (int k = j + 1; k <= n; ++k) {
                    if (k < n && a[k + 1] == a[k] + 1) continue;
                    for (int l = i, r = j + 1; r <= k; ++l, ++r) {
                        a[l] = a[r];
                    }
                    for (int r = i + k - j, l = i; l <= j; ++l, ++r) {
                        a[r] = copy2[l];
                    }
                    dfs(dep + 1, maxd);
                    if (fini) return;
                    for (int l = 1; l <= n; ++l) {
                        a[l] = copy1[l];
                    }
                } 
            }
        }
    }
}

int main() {
    while (scanf("%d", &n) && n) {
        memset(a, 0, sizeof(a)); fini = false;
        for (int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        for (int dep = 0; dep <= n; ++dep) {
            dfs(0, dep);
            if (fini) {
                ans = dep;
                break;
            }
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}