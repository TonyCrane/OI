/*************************************************************
 *  > File Name        : c1088_2.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/11/10 16:00:41
 *  > Algorithm        : 
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

const LL maxn = 2000010;
const LL mod  = 16777216;

LL n, d[maxn], K, B, P, p[maxn], ans;

struct Trie {
    int ch[maxn * 5 + 5][2], sz;
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    void insert(LL val) {
        LL p = 1;
        for (LL k = 30; k >= 0; --k) {
            LL c = val >> k & 1;
            if (ch[p][c] == 0) ch[p][c] = ++sz;
            p = ch[p][c];
        }
    }
    LL search(LL val) {
        LL p = 1, ans = 0;
        for (LL k = 30; k >= 0; --k) {
            LL c = val >> k & 1;
            if (ch[p][c ^ 1]) {
                p = ch[p][c ^ 1];
                ans |= 1 << k;
            } else {
                p = ch[p][c];
            }
        }
        return ans;
    }
}trie;

int main() {
    n = read(); K = read(); B = read(); P = read();
    d[1] = P % mod; trie.insert(d[1]);
    p[0] = 1;
    for (LL i = 1; i <= n; ++i) p[i] = p[i - 1] * 3 % mod;
    for (LL i = 2; i <= n; ++i) {
        d[i] = (K * d[i - 1] + B) % mod;
        trie.insert(d[i]);
    }
    for (LL i = 1; i <= n; ++i) {
        ans += p[i - 1] * trie.search(d[i]) % mod;
        ans %= mod;
    }
    printf("%lld\n", (ans + mod) % mod);
    return 0;
}