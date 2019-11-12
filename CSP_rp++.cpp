/*************************************************************
 *  > Description      : 复赛相关模板
 *  > File Name        : CSP_rp++.cpp
 *  > Author           : Tony_Wong
 *  > Created Time     : 2019/11/10 20:59:43
 *  > Copyright (C) 2019 Tony_Wong
**************************************************************/

#include <bits/stdc++.h>
using namespace std;

/* 读入优化 */
inline int read() {
    int x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - 48; ch = getchar();}
    return x * f;
}



/*-------- 存储及逻辑 --------*/ 
int       --> 2 ^ 31 - 1 --> 2e9  --> 4 bytes
long long --> 2 ^ 63 - 1 --> 9e18 --> 8 bytes
char      --> 2 ^ 7 - 1  --> 127  --> 1 byte

INT_MAX = 0x7fffffff
half_INT_MAX = 0x3f3f3f3f
LONGLONG_MAX = 0x7fffffffffffffff
memset(a, 0, sizeof(a));     0
memset(a, -1, sizeof(a));    -1
memset(a, 0x7f, sizeof(a));  inf
memset(a, 0x3f, sizeof(a));  inf / 2
memset(a, 0x80, sizeof(a));  -inf
memset(a, 0xc0, sizeof(a));  -inf / 2
memset(a, 0x43, sizeof(a));  double inf
memset(a, 0xfe, sizeof(a));  double -inf

1 << n  -->  2^n
n << 1  -->  2n
n >> 1  -->  n / 2 向下取整  //普通 n/2 向0取整

(n >> k) & 1        n在二进制下k位
n & ((1 << k) - 1)  n在二进制下后k位
n xor (1 << k)      n在二进制下k位取反
n | (1 << k)        n在二进制下k位赋值1
n & (~(1 << k))     n在二进制下k位赋值0

(n ^ 1) ^ 1 = n
n --> odd   n xor 1 = n - 1
n --> even  n xor 1 = n + 1

lowbit(x) = x & (~x + 1) = x & -x



/*-------- STL常用 --------*/
#include <vector>
vector<int> a;
a.size();
a.empty();
a.clear();
a.push_back();
a.pop_back();
a[ ]
vector<int>::iterator it;
for (it = a.begin(); it != a.end(); ++it) {
    *it;
}

#include <queue>
queue<int> q;
q.push(x);
q.pop();
q.size(); q.empty();
while (!q.empty()) q.pop();

priority_queue<int> pq1; //大根堆
priority_queue<int, vector<int>, greater<int> > pq2; //小根堆
pq1.push(x);   O(log n)
pq1.pop();     O(log n)
pq1.top();     O(1)
struct Node {
    int a, b;
    bool operator < (const Node& x) const {
        return a > x.a;
    }
};
priority_queue<Node> pq3;

#include <deque>
deque<int> dq;
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.push_back();
dq.front(); dq.back();
dq.clear();
dq[ ]

#include <set>
set<int> s;
multiset<int> ms;
bool operator < (const Node& a) const { /* ... */ }
s.size(); s.empty(); s.clear();
set<int>::iterator it;
it++; it--;                 O(log n)
s.insert(x); ms.insert(x);  O(log n)
s.find(x);                  O(log n) //返回迭代器
s.count(x); ms.count(x);    O(k + log n) //元素个数
s.erase(x);                 O(k + log n) //将值为x的全部删去
s.erase(it);                O(log n)     //删除迭代器所指位置
s.lower_bound(x);           O(log n) //查找>=x的最小元素 返回迭代器
s.upper_bound(x);           O(log n) //查找>x 的最小元素 返回迭代器

#include <map>
map<int, int> m;
m.size(); m.empty(); m.clear();
m.insert(pair<int, int>(x, y));
m.erase(pair<int, int>(x, y));
m.erase(it);
m.find(x);    O(log n) //查找键为x的二元组
m[key]        O(log n) //若不存在则会新建,值为广义0

#include <bitset>
bitset<64> bit;
~ & | ^ >> << == !=
bit[ ]
bit.count()

#include <algorithm>
reverse(a + 1, a + 1 + n);
reverse(a.begin(), a.end());
sort(a + 1, a + 1 + n, cmp); 
int id = lower_bound(a + 1, a + 1 + n, x) - a; //大于等于x的最小整数的下标



/*-------- 基础算法 --------*/
// 前缀和
for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i]; //l ~ r sum[r] - sum[l - 1];
for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
}

// 差分
b[1] = a[1];
for (int i = 1; i <= n; ++i) b[i] = a[i] - a[i - 1];

// 二分
int l = 0, r /*= maxans*/;
while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
        ans = mid;
        l = mid + 1;
    } else r = mid - 1;
}

// 三分
while (l < r) {
    int lmid = l + (r - l) / 3;
    int rmid = r - (r - l) / 3;
    if (F(rmid) > F(lmid)) r = rmid;
    else l = lmid;
}
ans: F(l)

// 离散化
for (int i = 1; i <= n; ++i) old[i] = a[i];
sort(old + 1, old + 1 + n);
int len = unique(old + 1, old + 1 + n) - old - 1;
for (int i = 1; i <= n; ++i) a[i] = lower_bound(old + 1, old + 1 + len, a[i]) - old;
old[a[i]] --> a[i]



/*-------- 数据结构 --------*/
// 堆
priority_queue<int> q;

// 并查集
int ufs[maxn], n;
int find(int x) { return ufs[x] == x ? x : ufs[x] = find(ufs[x]); }
void init() { for (int i = 1; i <= n; ++i) ufs[i] = i; }

int find(int x) {
    if (ufs[x] == x) return x;
    int root = find(ufs[x]);
    d[x] += d[ufs[x]];
    return ufs[x] = root;
}
void unionn(int x, int y) {
    x = find(x); y = find(y);
    ufs[x] = y; d[x] = siz[y];
    siz[y] += siz[x];
}

// ST表
int a[maxn], f[maxn][30], n, m;
for (int j = 1; j <= 20; ++j) {
    for (int i = 1; i <= n - (1 << j) + 1; ++i) {
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
}
for (int i = 1; i <= m; ++i) {
    int l = read(), r = read();
    int k = log(r - l + 1) / log(2);
    printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
}

// 树状数组
int t[maxn], n;
void add(int x, int k) { for (; x <= n; x += x & -x) t[x] += k; }
int ask(int x) { int res = 0; for (; x; x -= x & -x) res += t[x]; return res; }

// 树状数组求逆序对  注意要离散化!!!
for (int i = n; i; --i) {
    ans += ask(a[i] - 1);
    add(a[i], 1);
}

// 树状数组求二位偏序  注意FG要放在一起离散化!!!
for (LL i = n; i; --i) {
    ans += ask(F[i] - 1);
    add(G[i], 1);
}

// 二维树状数组
int t1[maxn][maxn];
int t2[maxn][maxn];
int t3[maxn][maxn];
int t4[maxn][maxn];
void add(int x, int y, int k) {
    for (int i = x; i <= n; i += i & -i) {
        for (int j = y; j <= m; j += j & -j) {
            t1[i][j] += k;
            t2[i][j] += k * x;
            t3[i][j] += k * y;
            t4[i][j] += k * x * y;
        }
    }
}
int ask(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i) {
        for (int j = y; j; j -= j & -j) {
            res += (x + 1) * (y + 1) * t1[i][j] - (y + 1) * t2[i][j] - (x + 1) * t3[i][j] + t4[i][j];
        }
    }
    return res;
}
/**
 * add(c + 1, d + 1, k);
 * add(a, d + 1, -k);
 * add(c + 1, b, -k);
 * add(a, b, k);
 * printf("%d\n", ask(c, d) - ask(c, b - 1) - ask(a - 1, d) + ask(a - 1, b - 1));
 **/

// 线段树
int n, m, a[maxn];
struct Node {
    int l, r;
    LL dat, laz;
    #define l(p) tree[p].l
    #define r(p) tree[p].r
    #define len(p) (tree[p].r - tree[p].l + 1)
    #define dat(p) tree[p].dat
    #define laz(p) tree[p].laz
}tree[maxn << 2];
void pushup(int p) {
    dat(p) = dat(p<<1) + dat(p<<1|1);
}
void pushdown(int p) {
    if (laz(p)) {
        laz(p<<1) += laz(p); laz(p<<1|1) += laz(p);
        dat(p<<1) += len(p<<1) * laz(p);
        dat(p<<1|1) += len(p<<1|1) * laz(p);
        laz(p) = 0;
    }
}
void build(int p, int l, int r) {
    l(p) = l; r(p) = r;
    if (l == r) {
        dat(p) = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}
void update(int p, int l, int r, int k) {
    if (l <= l(p) && r(p) <= r) {
        dat(p) += k * len(p);
        laz(p) += k;
        return;
    }
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1;
    if (l <= mid) update(p<<1, l, r, k);
    if (r >  mid) update(p<<1|1, l, r, k);
    pushup(p);
}
LL query(int p, int l, int r) {
    if (l <= l(p) && r(p) <= r) return dat(p);
    pushdown(p);
    int mid = (l(p) + r(p)) >> 1; LL ans = 0;
    if (l <= mid) ans += query(p<<1, l, r);
    if (r >  mid) ans += query(p<<1|1, l, r);
    return ans;
}

// 莫队
struct Query {
    int l, r, pos, id;
}q[maxn];
bool cmp(Query a, Query b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    if (a.pos & 1) return a.r > b.r;
    return a.r < b.r;
}
for (int i = 1; i <= m; ++i) {
    q[i].id = i;
    q[i].l = read();
    q[i].r = read();
    q[i].pos = q[i].l / len + 1;
}
sort(q + 1, q + 1 + m, cmp); l = 1;
for (int i = 1; i <= m; ++i) {
    while (l < q[i].l) del(l++);
    while (l > q[i].l) add(--l);
    while (r > q[i].r) del(r--);
    while (r < q[i].r) add(++r);
    ans[q[i].id] = Ans;
}

// Hash表
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
};

// Trie
struct Trie {
    int ch[maxn][26], sz, val[maxn];
    Trie() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
        memset( val , 0, sizeof( val ));
    }
    int idx(char c) { return c - 'a'; }
    void insert(char *s, int v) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
    }
    int search(char *s) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; ++i) {
            int c = idx(s[i]);
            if (!ch[u][c]) return -1;
            u = ch[u][c];
        }
        return val[u];
    }
};

// 平衡树Treap
struct Treap {
    int l, r, val, dat, cnt, siz;
    #define l(p) a[p].l
    #define r(p) a[p].r
    #define val(p) a[p].val
    #define dat(p) a[p].dat
    #define cnt(p) a[p].cnt
    #define siz(p) a[p].siz
}a[maxn];

int tot, root, n;

int New(int val) {
    val(++tot) = val;
    dat(tot)   = rand();
    cnt(tot)   = 1;
    siz(tot)   = 1;
    return tot;
}

void update(int p) {
    siz(p) = siz(l(p)) + cnt(p) + siz(r(p));
}

void build() {
    New(-inf); New(inf);
    root = 1; r(1) = 2;
    update(root);
}

int getRankByVal(int p, int val) {
    if (p == 0) return 0;
    if (val == val(p)) return siz(l(p)) + 1;
    if (val <  val(p)) return getRankByVal(l(p), val);
    return getRankByVal(r(p), val) + siz(l(p)) + cnt(p);
}

int getValByRank(int p, int rank) {
    if (p == 0) return inf;
    if (siz(l(p)) >= rank) return getValByRank(l(p), rank);
    if (siz(l(p)) + cnt(p) >= rank) return val(p);
    return getValByRank(r(p), rank - siz(l(p)) - cnt(p));
}

void zig(int& p) {
    int q = l(p);
    l(p) = r(q); r(q) = p; p = q;
    update(r(p)); update(p);
}

void zag(int & p) {
    int q = r(p);
    r(p) = l(q); l(q) = p; p = q;
    update(l(p)); update(p);
}

void insert(int& p, int val) {
    if (p == 0) {
        p = New(val);
        return;
    }
    if (val == val(p)) {
        cnt(p)++;
        update(p);
        return;
    }
    if (val < val(p)) {
        insert(l(p), val);
        if (dat(p) < dat(l(p))) zig(p);
    } else {
        insert(r(p), val);
        if (dat(p) < dat(r(p))) zag(p);
    }
    update(p);
}

int getPre(int val) {
    int ans = 1, p = root;
    while (p) {
        if (val == val(p)) {
            if (l(p) > 0) {
                p = l(p);
                while (r(p) > 0) p = r(p);
                ans = p;
            }
            break;
        }
        if (val(p) < val && val(p) > val(ans)) ans = p;
        p = val < val(p) ? l(p) : r(p);
    }
    return val(ans);
}

int getSuf(int val) {
    int ans = 2, p = root;
    while (p) {
        if (val == val(p)) {
            if (r(p) > 0) {
                p = r(p);
                while (l(p) > 0) p = l(p);
                ans = p;
            }
            break;
        }
        if (val(p) > val && val(p) < val(ans)) ans = p;
        p = val < val(p) ? l(p) : r(p);
    }
    return val(ans);
}

void remove(int& p, int val) {
    if (p == 0) return;
    if (val == val(p)) {
        if (cnt(p) > 1) {
            cnt(p)--; update(p);
            return;
        }
        if (l(p) || r(p)) {
            if (r(p) == 0 || dat(l(p)) > dat(r(p))) {
                zig(p); remove(r(p), val);
            } else {
                zag(p); remove(l(p), val);
            }
            update(p);
        } else p = 0;
        return;
    }
    if (val < val(p)) remove(l(p), val);
    else remove(r(p), val);
    update(p);
}



/*-------- 图论 --------*/
