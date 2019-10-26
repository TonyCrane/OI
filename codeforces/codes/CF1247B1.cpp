/*************************************************************
 *  > File Name        : CF1247B1.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/10/26 19:24:45
 *  > Algorithm        : +
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 200010;

int n, k, d, a[maxn], cnt[1000010];
set<int> s;

int main() {
    int T = read();
    while (T--) {
        s.clear(); memset(cnt, 0, sizeof(cnt));
        n = read(); k = read(); d = read();
        for (int i = 1; i <= n; ++i) a[i] = read();
        for (int i = 1; i <= d; ++i) {
            s.insert(a[i]);
            cnt[a[i]]++;
        }
        int ans = s.size();
        for (int i = d + 1; i <= n; ++i) {
            ans = min(ans, (int)s.size());
            if (cnt[a[i - d]] == 1) s.erase(a[i - d]);
            cnt[a[i - d]]--;
            s.insert(a[i]); 
            cnt[a[i]]++;
            ans = min(ans, (int)s.size());
        }
        printf("%d\n", ans);
    }
    return 0;
}