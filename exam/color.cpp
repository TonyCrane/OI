#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() {
    LL x = 0; LL f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}

LL p1, p2, k;

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T = read();
    while (T--) {
        p1 = read(); p2 = read(); k = read();
        if (p1 > p2) swap(p1, p2);
        LL g = gcd(p1, p2); LL l = p1 / g * p2;
        p1 /= g; p2 /= g;
        bool con1 = true; int cnt1 = 0;
        bool con2 = true; int cnt2 = 0;
        // printf("%lld\n", l);
        for (int i = 1; i <= l; ++i) {
            if (i % p2 == 0) {
                if (cnt1 >= k) {
                    con1 = false;
                    printf("No\n");
                    break;
                }
                cnt1 = 0;
            }
            if (i % p1 == 0) {
                cnt1++;
                // printf("%d: %d\n", i, cnt);
            }
        }
        if (con1) printf("Yes\n");
        // if (con) printf("Yes\n");
        // LL a1 = l / p1, a2 = l / p2;
        // if (a1 >= k * a2) {
        //     printf("No\n");
        // } else {
        //     printf("Yes\n");
        // }
    }
    return 0;
}