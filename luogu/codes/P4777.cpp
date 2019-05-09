/*************************************************************
 *  > File Name        : P4777.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/09 16:03:28
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL read(){
    LL f=1,x=0; char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}

LL mul_mod(LL a, LL b, LL n){
    LL res = 0;
    while (b > 0) {
        if (b & 1) res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}

void exgcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b) { d = a; x = 1; y = 0; }
    else { exgcd(b, a % b, d, y, x); y -= x * (a / b); }
}

LL excrt(LL n, LL* a, LL* m) {
    LL x, y, k, M = m[0], ans = a[0];
    for (int i = 1; i < n; ++i) {
        LL A = M, B = m[i], C = (a[i] - ans % B + B) % B, gcd;
        exgcd(A, B, gcd, x, y);
        LL bg = B / gcd;
        if (C % gcd != 0) return -1;
        x = mul_mod(x, C / gcd, bg);
        ans += x * M; M *= bg;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}

int main() {
    LL n = read(), a[100010], b[100010];
    for (LL i = 0; i < n; ++i) {
        a[i] = read(); b[i] = read(); 
    }
    printf("%lld\n", excrt(n, b, a));
    return 0;
}