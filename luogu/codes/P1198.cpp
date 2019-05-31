/*************************************************************
 *  > File Name        : P1198.cpp
 *  > Author           : Tony
 *  > Created Time     : 2019/05/30 15:21:35
 *  > Algorithm        : [DateStructure]SegmentTree
**************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200010;
const LL  inf  = (1LL << 63) - 2;

#define lt p<<1
#define rt p<<1|1
#define mid ((l+r)>>1)
#define lson lt,l,mid
#define rson rt,mid+1,r

LL SegmentTree[maxn << 2];

void add(int p, int l, int r, int x, LL k) {
    if (l == x && r == x) { SegmentTree[p] = k; return; }
    if (x <= mid) add(lson, x, k);
    if (x >  mid) add(rson, x, k);
    SegmentTree[p] = max(SegmentTree[lt], SegmentTree[rt]);
}

LL query(int p, int l, int r, int L, int R) {
    if (l >= L && r <= R) return SegmentTree[p];
    LL ans = -inf;
    if (L <= mid) ans = max(ans, query(lson, L, R));
    if (R >  mid) ans = max(ans, query(rson, L, R));
    return ans;
}

int main() {
    int m, d, p = 0;
    LL t = 0;
    scanf("%d %d", &m, &d);
    for (int i = 1; i <= m * 4; ++i) SegmentTree[i] = -inf;
    for (int i = 1; i <= m; ++i) {
        char opt[2]; LL a;
        scanf("%s %lld", opt, &a);
        if (opt[0] == 'A') {
            LL use = (a + t) % d;
            add(1, 1, m, ++p, use);
        } else {
            t = query(1, 1, m, p - a + 1, p) % d;
            printf("%lld\n", t);
        }
    }
    return 0;
}