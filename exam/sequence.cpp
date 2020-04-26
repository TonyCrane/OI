#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const int maxn = 1000010;
const LL mod  = 1e9 + 7;

LL n, ans;
LL a[maxn];
set<int> s;

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int l = 1; l <= n; ++l) {
        s.clear();
        for (int r = l; r <= n; ++r) {
            if (!s.count(a[r])) s.insert(a[r]);
            LL res = s.size();
            ans += res * res % mod;
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}